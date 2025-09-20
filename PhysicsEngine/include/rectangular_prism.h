#pragma once

#include "entity.h"
#include <Eigen/Dense>

namespace PhysicsEngine {
	class RectangularPrism : public PhysicsEngine::Entity {
	public:
		Eigen::Vector3f position;
		Eigen::Vector3f velocity;
		Eigen::Vector3f acceleration;

		Eigen::Matrix4f model;
		float vertices[8 * 3];
		unsigned int indices[6 * 2 * 3];

		float length;
		float width;
		float height;

		void tick(float ms);

		float* getVertices();
		unsigned int* getIndices();

		Eigen::Matrix4f* getModel();

		RectangularPrism(Eigen::Vector3f position, float length, float width, float height);
		~RectangularPrism();

	private:
		void updateModel();
	};
}