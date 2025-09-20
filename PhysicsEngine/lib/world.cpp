#include <vector>
#include <iostream>

#include "World.h"
#include "Entity.h"

namespace PhysicsEngine {
	World::World() {

	}
	World::~World() {
		std::cout << "Destroyed World\n";
	}
	void World::tick(float ms) {
		for (PhysicsEngine::Entity* entity : this->entities) {
			entity->tick(ms);
		}
	}
}
