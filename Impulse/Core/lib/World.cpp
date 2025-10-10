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
	void World::addEntity(Impulse::Core::Entity* entity) {
		this->entities.push_back(entity);
	}

	float* World::getVertices(unsigned int index) {
		return this->entities[index]->getVertices();
	}
	unsigned int* World::getIndices(unsigned int index) {
		return this->entities[index]->getIndices();
	}
	Eigen::Matrix4f* World::getModel(unsigned int index) {
		return this->entities[index]->getModel();
	}
}
