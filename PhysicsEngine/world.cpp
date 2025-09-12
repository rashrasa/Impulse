#include "pch.h"
#include "framework.h"

#include <Eigen/Dense>
#include <vector>
#include "entity.h"
#include <iostream>

class World {
public:
	std::vector<PhysicsEngine::Entity*> entities;

	World() {

	}

	~World() {
		for (auto element : entities) {
			delete element;
		}
		std::cout << "Destroyed World\n";
	}


};