#pragma once

#include <Eigen/Dense>

namespace PhysicsEngine {
	class Entity {
	private:
	public:
		Eigen::Matrix4f model;
		virtual void tick(float ms) = 0;
		virtual float* getVertices() = 0;
		virtual unsigned int getNumVertices() = 0;
		virtual float* getIndices() = 0;
		virtual unsigned int getNumIndices() = 0;

	private:
	};
}