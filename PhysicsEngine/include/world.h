#pragma once

#include <vector>

#include "Entity.h"

namespace PhysicsEngine {
	class World {
	public:
		std::vector<PhysicsEngine::Entity* > entities;
		void tick(float ms);
		World();
		~World();
	};
}