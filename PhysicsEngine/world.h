#pragma once

#include "entity.h"
#include <vector>

namespace PhysicsEngine {
	struct World {
		std::vector<PhysicsEngine::Entity*> entities;
	};
}