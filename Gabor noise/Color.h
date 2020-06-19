#pragma once
#include<map>

class ColorSetting;
class ColorPainter;
namespace Karl07 {
	using std::map;
	class Color {
	public:
		int r, g, b;
		Color(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) {}
		Color operator*(float x) { return Color(r*x, g*x, b*x); }
		Color operator+(Color const& other) { return Color(r + other.r, g + other.g, b + other.b); }
	};
	class ColorMap {
		friend ColorSetting;
		friend ColorPainter;
	protected:
		map<int, Color> color_map;
	public:
		ColorMap();
		void SetColor(int x, int r, int g, int b);
		void DelColor(int x);
		Color Mapping(int x);
	};
}