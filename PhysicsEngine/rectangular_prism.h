#pragma once

#include "entity.h"
#include <Eigen/Dense>

namespace PhysicsEngine {
	class RectangularPrism : public PhysicsEngine::Entity {
	public:
		Eigen::Vector3f position;
		Eigen::Vector3f velocity;
		Eigen::Vector3f acceleration;

		float length;
		float width;
		float height;

		void tick(float ms);
		
		RectangularPrism();
		RectangularPrism(Eigen::Vector3f position);
		~RectangularPrism();
	};
}