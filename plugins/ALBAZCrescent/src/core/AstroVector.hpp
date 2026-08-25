#ifndef ALBAZ_ASTROVECTOR_HPP
#define ALBAZ_ASTROVECTOR_HPP

#include <cmath>

struct Vec3
{
	double x{0.0};
	double y{0.0};
	double z{0.0};

	constexpr Vec3() noexcept = default;
	constexpr Vec3(double xValue, double yValue, double zValue) noexcept
		: x(xValue), y(yValue), z(zValue)
	{
	}

	[[nodiscard]] constexpr Vec3 operator+(const Vec3& other) const noexcept
	{
		return {x + other.x, y + other.y, z + other.z};
	}

	[[nodiscard]] constexpr Vec3 operator-(const Vec3& other) const noexcept
	{
		return {x - other.x, y - other.y, z - other.z};
	}

	[[nodiscard]] constexpr Vec3 operator*(double scale) const noexcept
	{
		return {x * scale, y * scale, z * scale};
	}

	[[nodiscard]] constexpr double dot(const Vec3& other) const noexcept
	{
		return x * other.x + y * other.y + z * other.z;
	}

	[[nodiscard]] constexpr Vec3 cross(const Vec3& other) const noexcept
	{
		return {
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		};
	}

	[[nodiscard]] double norm() const noexcept
	{
		return std::sqrt(dot(*this));
	}
};

[[nodiscard]] constexpr Vec3 operator*(double scale, const Vec3& vector) noexcept
{
	return vector * scale;
}

#endif // ALBAZ_ASTROVECTOR_HPP
