#include "pch.h"
#include "framework.h"

#include <Eigen/Dense>
#include <iostream>

#include "rectangular_prism.h"

namespace PhysicsEngine {
	RectangularPrism::RectangularPrism(Eigen::Vector3f position, float length, float width, float height)
		:vertices{
			-width / 2.0f, -height / 2.0f, -length / 2.0f, // left front bottom
			 width / 2.0f, -height / 2.0f, -length / 2.0f, // right front bottom
			 width / 2.0f, -height / 2.0f,  length / 2.0f, // right front top
			-width / 2.0f, -height / 2.0f,  length / 2.0f, // left front top

			-width / 2.0f, height / 2.0f, -length / 2.0f, // left back bottom
			 width / 2.0f, height / 2.0f, -length / 2.0f, // right back bottom
			 width / 2.0f, height / 2.0f,  length / 2.0f, // right back top
			-width / 2.0f, height / 2.0f,  length / 2.0f, // left back top
		} {
		std::cout << "initializing rect" << std::endl;
		this->position = position;
		this->velocity << 0, 0, 0;
		this->acceleration << 0, 0, 0;
		std::cout << "initialized vectors" << std::endl;
		this->length = length;
		this->width = width;
		this->height = height;
		std::cout << "initialized dimensions" << std::endl;
		this->model = Eigen::Matrix4f();
		(this->model) <<
			width, 0, 0, position.x(),
			0, height, 0, position.y(),
			0, 0, length, position.z(),
			0, 0, 0, 1;
		std::cout << this->model.format(Eigen::IOFormat(4, 0, " ", "\n", "|", "|", "", "", 32)) << std::endl;
		this->updateModel();
		std::cout << "updated model" << std::endl;
	}
	RectangularPrism::~RectangularPrism() {
		std::cout << "Deleted object\n";
	}

	void RectangularPrism::tick(float ms) {
		this->velocity += this->acceleration * (ms / 1000.0);
		this->position += this->velocity * (ms / 1000.0);

		this->updateModel();
	}

	void RectangularPrism::updateModel() {
		(this->model)(0, 3) = position.x();
		(this->model)(1, 3) = position.y();
		(this->model)(2, 3) = position.z();
	}

	// Length of 
	float* RectangularPrism::getVertices() {
		return this->vertices;
	}

	unsigned int RectangularPrism::getNumVertices() {
		return this->nVertices;
	}

	float* RectangularPrism::getIndices() {
		return this->indices;
	}

	unsigned int RectangularPrism::getNumIndices() {
		return this->nIndices;
	}
}


