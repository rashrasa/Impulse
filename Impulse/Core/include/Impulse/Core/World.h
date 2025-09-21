#pragma once

#include <vector>

#include "Entity.h"

namespace impulse::core {
	class World {
	public:
		std::vector<impulse::core::Entity* > entities;
		void tick(float ms);
		World();
		~World();
	};
}