#pragma once

#include <Eigen/Dense>

namespace PhysicsEngine {
	class Rectangle: public PhysicsEngine::Entity {
	public:
		Eigen::Vector3f position;
		Eigen::Vector3f velocity;
		Eigen::Vector3f acceleration;

		float length = 0;
		float width = 0;
		~Rectangle() override {
			std::cout << "Destroying Rectangle";
		}
	};
}