#pragma once

#include <Eigen/Dense>

namespace PhysicsEngine {
	class Rectangle: public PhysicsEngine::Entity {
	public:
		Eigen::Vector3f position;
		Eigen::Vector3f velocity;
		Eigen::Vector3f acceleration;

		float length;
		float width;
	};
}