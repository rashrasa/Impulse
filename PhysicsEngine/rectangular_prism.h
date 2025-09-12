#pragma once

#include <Eigen/Dense>

namespace PhysicsEngine {
	class RectangularPrism : public PhysicsEngine::Entity {
	public:
		Eigen::Vector3f position;
		Eigen::Vector3f velocity;
		Eigen::Vector3f acceleration;

		float length = 0;
		float width = 0;
		float height = 0;

		void tick(float ms) {};

		RectangularPrism() = default;
		~RectangularPrism() = default;
	};
}