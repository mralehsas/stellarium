#ifndef ALBAZ_TESTTIMECALENDARANGLES_HPP
#define ALBAZ_TESTTIMECALENDARANGLES_HPP

#include <QObject>

class TestTimeCalendarAngles : public QObject
{
	Q_OBJECT

private slots:
	void angleNormalizationIsStableAcrossWrap();
	void calendarLeapRulesRemainDistinct();
	void gregorianReformBoundaryIsContinuousInJD();
	void historical622JulianDateHasUnambiguousJD();
	void j2000MidnightMatchesReferenceJD();
	void calendarRoundTripPreservesRequestedConvention();
	void timeScaleIsExplicitlyTagged();
};

#endif // ALBAZ_TESTTIMECALENDARANGLES_HPP
