#pragma once

#include <vector>

#include "Entity.h"

namespace Impulse::Core {
	class World {
	public:
		std::vector<Impulse::Core::Entity* > entities;
		void tick(float ms);
		World();
		~World();
	};
}