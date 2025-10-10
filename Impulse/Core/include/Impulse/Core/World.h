#pragma once

#include <vector>
#include <Eigen/Dense>

#include "Entity.h"

namespace Impulse::Core {
	class World {
	private:
		std::vector<Impulse::Core::Entity* > entities;
	public:
		void tick(float ms);
		void addEntity(Impulse::Core::Entity* entity);
		float* getVertices(unsigned int index);
		unsigned int* getIndices(unsigned int index);
		Eigen::Matrix4f* getModel(unsigned int index);
		World();
		~World();
	};
}