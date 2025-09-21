#include <vector>
#include <iostream>

#include "Impulse/Core/World.h"
#include "Impulse/Core/Entity.h"

namespace Impulse::Core {
	World::World() {

	}
	World::~World() {
		std::cout << "Destroyed World\n";
	}
	void World::tick(float ms) {
		for (Impulse::Core::Entity* entity : this->entities) {
			entity->tick(ms);
		}
	}
}
