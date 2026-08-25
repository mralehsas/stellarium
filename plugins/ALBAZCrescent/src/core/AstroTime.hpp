#ifndef ALBAZ_ASTROTIME_HPP
#define ALBAZ_ASTROTIME_HPP

enum class TimeScale
{
	UTC,
	TAI,
	TT,
	UT1,
	TDB
};

class AstroJulianDate
{
public:
	explicit constexpr AstroJulianDate(double value, TimeScale scale) noexcept
		: m_value(value)
		, m_scale(scale)
	{
	}

	constexpr double value() const noexcept { return m_value; }
	constexpr TimeScale scale() const noexcept { return m_scale; }

private:
	double m_value;
	TimeScale m_scale;
};

class AstroTime
{
public:
	static constexpr double ttMinusTaiSeconds() noexcept { return 32.184; }
};

#endif // ALBAZ_ASTROTIME_HPP
