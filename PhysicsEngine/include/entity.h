#pragma once

#include <Eigen/Dense>

namespace PhysicsEngine {
	class Entity {
	private:
	public:
		virtual void tick(float ms) = 0;
		virtual float* getVertices() = 0;
		virtual unsigned int* getIndices() = 0;
		virtual Eigen::Matrix4f* getModel() = 0;
	private:
	};
}