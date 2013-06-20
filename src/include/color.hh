// File: color.hh
// Date: Fri Jun 21 00:18:00 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include "geometry/geometry.hh"

#include <cmath>

class Color: public Vector {
	public:
		Color(real_t r = 0, real_t g = 0, real_t b = 0):
			Vector(r, g, b){}

		Color(const Vec& v):
			Vector(v.x, v.y, v.z){}

		static constexpr real_t C_EPS = 1e-4;

		bool black() const
		{ return is_zero(C_EPS); }

		void check() const {
			if (x < 0 || x > 1 + EPS || y < 0 || y > 1 + EPS || z < 0 || z > 1 + EPS)
				cout << (*this) << endl;
			m_assert(x >= 0 && x <= 1 + EPS);
			m_assert(y >= 0 && y <= 1 + EPS);
			m_assert(z >= 0 && z <= 1 + EPS);
		}

		void normalize();

		Color operator * (real_t p) const
		{ return Color(x * p, y * p, z * p); }

		Color operator * (const Vector& c) const
		{ return Color(x * c.x, y * c.y, z * c.z); }

		static const Color WHITE, BLACK, RED, BLUE, GREEN, YELLOW, MAGNETA, CYAN;

};


class Light {

	public:
		Light(const Vec& _src, const Color& col, real_t _intense):
			src(_src), color(col), intensity(_intense){};

		Vec src;
		Color color;
		real_t intensity;
		real_t size = EPS;
};
