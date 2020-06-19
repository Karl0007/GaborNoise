#include "Color.h"
#include <iostream>
namespace Karl07 {

	ColorMap::ColorMap()
	{
		color_map[0] = Color(0, 0, 0);
		color_map[255] = Color(255, 255, 255);
	}

	void ColorMap::SetColor(int x, int r, int g, int b)
	{
		color_map[x] = Color(r, g, b);
	}

	void ColorMap::DelColor(int x)
	{
		color_map.erase(x);
	}

	Color ColorMap::Mapping(int x)
	{
		auto r = color_map.lower_bound(x);
		if (r->first == x) {
			return r->second;
		}
		else {
			auto l = r;
			l--;
			float len = r->first - l->first;
			float p1 = (x - l->first) / len;
			float p2 = (r->first - x) / len;
			//std::cout <<l->first<<" " << x <<" " << p1 << " " << p2 << std::endl;
			return l->second*p2 + r->second*p1;
		}
	}
}