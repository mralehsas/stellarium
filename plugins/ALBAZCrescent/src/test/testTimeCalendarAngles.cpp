#include "testTimeCalendarAngles.hpp"

#include "../core/AstroAngle.hpp"
#include "../core/AstroTime.hpp"
#include "../core/CalendarConversion.hpp"

#include <QtTest>

#include <cmath>
#include <limits>
#include <type_traits>

QTEST_GUILESS_MAIN(TestTimeCalendarAngles)

void TestTimeCalendarAngles::angleNormalizationIsStableAcrossWrap()
{
	QCOMPARE(AstroAngle::normalize360(360.0), 0.0);
	QCOMPARE(AstroAngle::normalize360(-10.0), 350.0);
	QCOMPARE(AstroAngle::normalize360(1095.0), 15.0);

	QCOMPARE(AstroAngle::normalizeSigned180(181.0), -179.0);
	QCOMPARE(AstroAngle::normalizeSigned180(-181.0), 179.0);
	QCOMPARE(AstroAngle::normalizeSigned180(180.0), -180.0);
	QCOMPARE(AstroAngle::separationDegrees(359.0, 1.0), 2.0);

	QVERIFY(std::isnan(AstroAngle::normalize360(std::numeric_limits<double>::quiet_NaN())));
}

void TestTimeCalendarAngles::calendarLeapRulesRemainDistinct()
{
	QVERIFY(CalendarConversion::isLeapYear(1900, CalendarSystem::Julian));
	QVERIFY(!CalendarConversion::isLeapYear(1900, CalendarSystem::ProlepticGregorian));
	QVERIFY(CalendarConversion::isLeapYear(2000, CalendarSystem::ProlepticGregorian));
}

void TestTimeCalendarAngles::gregorianReformBoundaryIsContinuousInJD()
{
	const CalendarDate julianLast{1582, 10, 4, CalendarSystem::Julian};
	const CalendarDate gregorianFirst{1582, 10, 15, CalendarSystem::ProlepticGregorian};

	const double jdJulian = CalendarConversion::toJulianDay0h(julianLast);
	const double jdGregorian = CalendarConversion::toJulianDay0h(gregorianFirst);

	QCOMPARE(jdJulian, 2299159.5);
	QCOMPARE(jdGregorian, 2299160.5);
	QCOMPARE(jdGregorian - jdJulian, 1.0);
}

void TestTimeCalendarAngles::historical622JulianDateHasUnambiguousJD()
{
	const CalendarDate julian{622, 7, 19, CalendarSystem::Julian};
	const CalendarDate prolepticGregorian{622, 7, 22, CalendarSystem::ProlepticGregorian};

	const double jdJulian = CalendarConversion::toJulianDay0h(julian);
	const double jdGregorian = CalendarConversion::toJulianDay0h(prolepticGregorian);

	QCOMPARE(jdJulian, 1948442.5);
	QCOMPARE(jdGregorian, 1948442.5);
}

void TestTimeCalendarAngles::j2000MidnightMatchesReferenceJD()
{
	const CalendarDate j2000Date{2000, 1, 1, CalendarSystem::ProlepticGregorian};
	QCOMPARE(CalendarConversion::toJulianDay0h(j2000Date), 2451544.5);
}

void TestTimeCalendarAngles::calendarRoundTripPreservesRequestedConvention()
{
	constexpr double jd = 1948442.5;

	const CalendarDate julian = CalendarConversion::fromJulianDay0h(jd, CalendarSystem::Julian);
	QCOMPARE(julian.year, 622);
	QCOMPARE(julian.month, 7);
	QCOMPARE(julian.day, 19);
	QCOMPARE(julian.calendar, CalendarSystem::Julian);

	const CalendarDate gregorian = CalendarConversion::fromJulianDay0h(jd, CalendarSystem::ProlepticGregorian);
	QCOMPARE(gregorian.year, 622);
	QCOMPARE(gregorian.month, 7);
	QCOMPARE(gregorian.day, 22);
	QCOMPARE(gregorian.calendar, CalendarSystem::ProlepticGregorian);
}

void TestTimeCalendarAngles::timeScaleIsExplicitlyTagged()
{
	static_assert(!std::is_convertible_v<double, AstroJulianDate>,
	              "A naked double must not silently become a tagged astronomical instant");

	const AstroJulianDate tt{2451545.0, TimeScale::TT};
	QCOMPARE(tt.value(), 2451545.0);
	QCOMPARE(tt.scale(), TimeScale::TT);
	QVERIFY(tt.scale() != TimeScale::UTC);
	QCOMPARE(AstroTime::ttMinusTaiSeconds(), 32.184);
}
