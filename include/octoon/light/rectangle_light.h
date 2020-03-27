#ifndef OCTOON_RECTANGLE_LIGHT_H_
#define OCTOON_RECTANGLE_LIGHT_H_

#include <octoon/light/light.h>

namespace octoon::light
{
	class OCTOON_EXPORT RectangleLight final : public Light
	{
		OctoonDeclareSubClass(RectangleLight, Light)
	public:
		RectangleLight() noexcept;
		virtual ~RectangleLight() noexcept;

		video::RenderObjectPtr clone() const noexcept;

	private:
		RectangleLight(const RectangleLight&) noexcept = delete;
		RectangleLight& operator=(const RectangleLight&) noexcept = delete;
	};
}

#endif