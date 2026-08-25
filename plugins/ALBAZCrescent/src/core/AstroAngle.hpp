#ifndef ALBAZ_ASTROANGLE_HPP
#define ALBAZ_ASTROANGLE_HPP

#include <cmath>

namespace AstroAngle
{
inline double normalize360(double degrees) noexcept
{
	if (!std::isfinite(degrees))
		return degrees;

	double normalized = std::fmod(degrees, 360.0);
	if (normalized < 0.0)
		normalized += 360.0;
	if (normalized >= 360.0)
		normalized -= 360.0;

	return normalized == 0.0 ? 0.0 : normalized;
}

inline double normalizeSigned180(double degrees) noexcept
{
	if (!std::isfinite(degrees))
		return degrees;

	return normalize360(degrees + 180.0) - 180.0;
}

inline double separationDegrees(double firstDegrees, double secondDegrees) noexcept
{
	return std::fabs(normalizeSigned180(secondDegrees - firstDegrees));
}
}

#endif // ALBAZ_ASTROANGLE_HPP
