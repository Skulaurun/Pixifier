#pragma once

#include <tuple>
#include <type_traits>

template<typename T>
struct Vector2D {
	static_assert(std::is_arithmetic_v<T>);

public:
	T x, y;

public:
	Vector2D() : x(0), y(0) {}
	Vector2D(const T& n) : x(n), y(n) {}
	Vector2D(const T& x, const T& y) : x(x), y(y) {}
	Vector2D(const Vector2D& v) : x(v.x), y(v.y) {}

	template<typename O>
	Vector2D& operator+=(const Vector2D<O>& other) {
		x += static_cast<T>(other.x); y += static_cast<T>(other.y);
		return *this;
	}
	template<typename O>
	Vector2D& operator-=(const Vector2D<O>& other) {
		x -= static_cast<T>(other.x); y -= static_cast<T>(other.y);
		return *this;
	}
	template<typename O>
	Vector2D& operator*=(const Vector2D<O>& other) {
		x *= static_cast<T>(other.x); y *= static_cast<T>(other.y);
		return *this;
	}
	template<typename O>
	Vector2D& operator/=(const Vector2D<O>& other) {
		x /= static_cast<T>(other.x); y /= static_cast<T>(other.y);
		return *this;
	}

	Vector2D operator-() const { return Vector2D(-x, -y); }
	T& operator[](const std::size_t index) { return *((T*)this + index); }

	template<typename O>
	operator Vector2D<O>() const {
		return Vector2D<O>(static_cast<O>(x), static_cast<O>(y));
	}

};

template<typename T1, typename T2>
auto operator+(const Vector2D<T1>& left, const Vector2D<T2>& right) -> Vector2D<typename std::remove_const<decltype(left.x + right.x)>::type> {
	using type = typename std::remove_const<decltype(left.x + right.x)>::type;
	return Vector2D<type>(left.x + right.x, left.y + right.y);
}
template<typename T1, typename T2>
auto operator-(const Vector2D<T1>& left, const Vector2D<T2>& right) -> Vector2D<typename std::remove_const<decltype(left.x - right.x)>::type> {
	using type = typename std::remove_const<decltype(left.x - right.x)>::type;
	return Vector2D<type>(left.x - right.x, left.y - right.y);
}
template<typename T1, typename T2>
auto operator*(const Vector2D<T1>& left, const Vector2D<T2>& right) -> Vector2D<typename std::remove_const<decltype(left.x * right.x)>::type> {
	using type = typename std::remove_const<decltype(left.x * right.x)>::type;
	return Vector2D<type>(left.x * right.x, left.y * right.y);
}
template<typename T1, typename T2>
auto operator/(const Vector2D<T1>& left, const Vector2D<T2>& right) -> Vector2D<typename std::remove_const<decltype(left.x / right.x)>::type> {
	using type = typename std::remove_const<decltype(left.x / right.x)>::type;
	return Vector2D<type>(left.x / right.x, left.y / right.y);
}

template<typename T1, typename T2>
bool operator==(const Vector2D<T1>& left, const Vector2D<T2>& right) {
	return std::tie(left.x, left.y) == std::tie(right.x, right.y);
}
template<typename T1, typename T2>
bool operator!=(const Vector2D<T1>& left, const Vector2D<T2>& right) {
	return !(left == right);
}

template<typename T1, typename T2>
bool operator<(const Vector2D<T1>& left, const Vector2D<T2>& right) {
	return std::tie(left.x, left.y) < std::tie(right.x, right.y);
}
template<typename T1, typename T2>
bool operator>(const Vector2D<T1>& left, const Vector2D<T2>& right) {
	return right < left;
}
template<typename T1, typename T2>
bool operator>=(const Vector2D<T1>& left, const Vector2D<T2>& right) {
	return !(left < right);
}
template<typename T1, typename T2>
bool operator<=(const Vector2D<T1>& left, const Vector2D<T2>& right) {
	return !(right < left);
}

typedef Vector2D<int> IVec2;
typedef Vector2D<float> FVec2;
