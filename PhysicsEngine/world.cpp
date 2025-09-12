#include "pch.h"
#include "framework.h"

#include <vector>
#include "entity.h"
#include <iostream>

#include "world.h"

namespace PhysicsEngine {
	World::World() {

	}
	World::~World() {
		std::cout << "Destroyed World\n";
	}
}
