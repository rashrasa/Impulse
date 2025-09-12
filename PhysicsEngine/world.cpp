#include "pch.h"
#include "framework.h"

#include <Eigen/Dense>
#include <vector>
#include "entity.h"

struct World {
	std::vector<PhysicsEngine::Entity*> entities;
	~World() {
		for (auto element: entities) {
			delete element;
		}
	}
};