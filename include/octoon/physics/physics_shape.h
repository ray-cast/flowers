#ifndef OCTOON_PHYSICS_SHAPE_H_
#define OCTOON_PHYSICS_SHAPE_H_

#include <octoon/runtime/platform.h>
#include <octoon/math/math.h>

#include <octoon/physics/physics_scene.h>

namespace octoon
{
	namespace physics
	{
		class OCTOON_EXPORT PhysicsShape
		{
		public:
			PhysicsShape() noexcept;
			virtual ~PhysicsShape() noexcept;

			virtual math::float3 getCenter() = 0;
			virtual void setCenter(math::float3 position) = 0;

		private:
			PhysicsShape(const PhysicsShape&) noexcept = delete;
			PhysicsShape& operator=(const PhysicsShape&) noexcept = delete;
		};
	}
}

#endif