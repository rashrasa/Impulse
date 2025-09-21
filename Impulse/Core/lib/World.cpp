#include <vector>
#include <iostream>

#include "Impulse/Core/World.h"
#include "Impulse/Core/Entity.h"

namespace impulse::core {
	World::World() {

	}
	World::~World() {
		std::cout << "Destroyed World\n";
	}
	void World::tick(float ms) {
		for (impulse::core::Entity* entity : this->entities) {
			entity->tick(ms);
		}
	}
}
