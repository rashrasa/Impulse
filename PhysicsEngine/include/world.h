#pragma once

#include "entity.h"
#include <vector>

namespace PhysicsEngine {
	class World {
	public:
		std::vector<PhysicsEngine::Entity* > entities;
		void tick(float ms);
		World();
		~World();
	};
}