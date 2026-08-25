#ifndef ALBAZ_CALENDARCONVERSION_HPP
#define ALBAZ_CALENDARCONVERSION_HPP

#include <cmath>

enum class CalendarSystem
{
	Julian,
	ProlepticGregorian
};

struct CalendarDate
{
	int year;
	int month;
	int day;
	CalendarSystem calendar;
};

class CalendarConversion
{
public:
	static bool isLeapYear(int year, CalendarSystem calendar) noexcept
	{
		if (calendar == CalendarSystem::Julian)
			return year % 4 == 0;

		if (year % 4 != 0)
			return false;
		if (year % 100 != 0)
			return true;
		return year % 400 == 0;
	}

	static double toJulianDay0h(const CalendarDate& date) noexcept
	{
		int year = date.year;
		int month = date.month;
		if (month <= 2)
		{
			--year;
			month += 12;
		}

		double correction = 0.0;
		if (date.calendar == CalendarSystem::ProlepticGregorian)
		{
			const double century = std::floor(static_cast<double>(year) / 100.0);
			correction = 2.0 - century + std::floor(century / 4.0);
		}

		return std::floor(365.25 * (static_cast<double>(year) + 4716.0))
		       + std::floor(30.6001 * (static_cast<double>(month) + 1.0))
		       + static_cast<double>(date.day)
		       + correction
		       - 1524.5;
	}

	static CalendarDate fromJulianDay0h(double julianDay, CalendarSystem calendar) noexcept
	{
		const double z = std::floor(julianDay + 0.5);
		double a = z;
		if (calendar == CalendarSystem::ProlepticGregorian)
		{
			const double alpha = std::floor((z - 1867216.25) / 36524.25);
			a = z + 1.0 + alpha - std::floor(alpha / 4.0);
		}

		const double b = a + 1524.0;
		const double c = std::floor((b - 122.1) / 365.25);
		const double d = std::floor(365.25 * c);
		const double e = std::floor((b - d) / 30.6001);

		const int day = static_cast<int>(b - d - std::floor(30.6001 * e));
		const int month = static_cast<int>(e < 14.0 ? e - 1.0 : e - 13.0);
		const int year = static_cast<int>(month > 2 ? c - 4716.0 : c - 4715.0);

		return CalendarDate{year, month, day, calendar};
	}
};

#endif // ALBAZ_CALENDARCONVERSION_HPP
