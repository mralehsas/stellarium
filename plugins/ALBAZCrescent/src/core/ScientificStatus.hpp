#ifndef ALBAZ_SCIENTIFICSTATUS_HPP
#define ALBAZ_SCIENTIFICSTATUS_HPP

#include <QString>

#include <utility>

enum class Severity
{
	Ok,
	Informational,
	Warning,
	RecoverableScientific,
	FatalScientific
};

struct ScientificStatus
{
	Severity severity{Severity::Ok};
	QString code;
	QString message;

	[[nodiscard]] bool usable() const noexcept
	{
		return severity != Severity::FatalScientific;
	}

	[[nodiscard]] bool fatalScientific() const noexcept
	{
		return severity == Severity::FatalScientific;
	}

	[[nodiscard]] static ScientificStatus fatal(QString codeValue, QString messageValue)
	{
		ScientificStatus status;
		status.severity = Severity::FatalScientific;
		status.code = std::move(codeValue);
		status.message = std::move(messageValue);
		return status;
	}
};

#endif // ALBAZ_SCIENTIFICSTATUS_HPP
