#ifndef ALBAZ_PROVENANCE_HPP
#define ALBAZ_PROVENANCE_HPP

#include <QByteArray>
#include <QCryptographicHash>
#include <QString>

struct Provenance
{
	QString ephemerisId;
	QString kernelSha256;
	double kernelStartJd{0.0};
	double kernelEndJd{0.0};
	QString eopSource;
	QString deltaTModel;
	QString algorithmId;
	QString algorithmVersion;

	[[nodiscard]] QString fingerprint() const
	{
		QByteArray payload;

		auto appendField = [&payload](const QString& value)
		{
			const QByteArray encoded = value.toUtf8();
			payload.append(QByteArray::number(encoded.size()));
			payload.append(':');
			payload.append(encoded);
			payload.append('|');
		};

		appendField(ephemerisId);
		appendField(kernelSha256);
		appendField(QString::number(kernelStartJd, 'g', 17));
		appendField(QString::number(kernelEndJd, 'g', 17));
		appendField(eopSource);
		appendField(deltaTModel);
		appendField(algorithmId);
		appendField(algorithmVersion);

		return QString::fromLatin1(
			QCryptographicHash::hash(payload, QCryptographicHash::Sha256).toHex());
	}
};

#endif // ALBAZ_PROVENANCE_HPP
