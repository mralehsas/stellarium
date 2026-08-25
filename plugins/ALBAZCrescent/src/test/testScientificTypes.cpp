#include "testScientificTypes.hpp"

#include "../core/AstroVector.hpp"
#include "../core/Provenance.hpp"
#include "../core/ScientificStatus.hpp"

#include <QtTest>

QTEST_GUILESS_MAIN(TestScientificTypes)

void TestScientificTypes::fatalStatusIsNotUsable()
{
	const ScientificStatus s = ScientificStatus::fatal(
		QStringLiteral("DE441_OUT_OF_RANGE"),
		QStringLiteral("Requested epoch is outside kernel coverage"));

	QVERIFY(!s.usable());
	QCOMPARE(s.severity, Severity::FatalScientific);
	QCOMPARE(s.code, QStringLiteral("DE441_OUT_OF_RANGE"));
}

void TestScientificTypes::provenanceFingerprintChangesWithKernel()
{
	Provenance a;
	a.ephemerisId = QStringLiteral("DE440");
	a.kernelSha256 = QStringLiteral("aaa");
	a.kernelStartJd = 2287184.5;
	a.kernelEndJd = 2688976.5;

	Provenance b = a;
	b.ephemerisId = QStringLiteral("DE441");

	QVERIFY(!a.fingerprint().isEmpty());
	QVERIFY(a.fingerprint() != b.fingerprint());
}

void TestScientificTypes::vectorArithmeticIsDoublePrecision()
{
	const Vec3 a{1.0, 2.0, 3.0};
	const Vec3 b{4.0, -2.0, 0.5};
	const Vec3 c = a + b;

	QCOMPARE(c.x, 5.0);
	QCOMPARE(c.y, 0.0);
	QCOMPARE(c.z, 3.5);
	QCOMPARE(a.dot(b), 1.5);

	const Vec3 cross = a.cross(b);
	QCOMPARE(cross.x, 7.0);
	QCOMPARE(cross.y, 11.5);
	QCOMPARE(cross.z, -10.0);
}
