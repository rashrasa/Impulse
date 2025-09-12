#pragma once

#include "entity.h"
#include <vector>

namespace PhysicsEngine {
	class World {
	public:
		std::vector<PhysicsEngine::Entity*> entities;
		World() = default;
		~World() = default;
	};
}