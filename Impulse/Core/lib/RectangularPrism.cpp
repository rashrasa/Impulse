#include <Eigen/Dense>
#include <iostream>

#include "Impulse/Core/RectangularPrism.h"

namespace Impulse::Core {
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
		}, indices{
			0, 1, 2,	2, 3, 0, // front
			1, 5, 6,	6, 2, 1, // right
			2, 6, 7,	7, 3, 2, // top
			4, 0, 3,	3, 7, 4, // left
			0, 1, 5,	5, 4, 0, // bottom
			5, 6, 7,	7, 4, 5, // back
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
			1, 0, 0, position.x(),
			0, 1, 0, position.y(),
			0, 0, 1, position.z(),
			0, 0, 0, 1;
		std::cout << this->model.format(Eigen::IOFormat(4, 0, " ", "\n", "|", "|", "", "", 32)) << std::endl;
		std::cout << this->position.format(Eigen::IOFormat(4, 0, " ", "\n", "|", "|", "", "", 32)) << std::endl;

		std::cout << this->vertices[0] << std::endl;
		std::cout << this->indices[0] << std::endl;

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
		(this->model)(0, 3) = position(0);
		(this->model)(1, 3) = position(1);
		(this->model)(2, 3) = position(2);
	}

	// Length of 
	float* RectangularPrism::getVertices() {
		return this->vertices;
	}

	unsigned int* RectangularPrism::getIndices() {
		return this->indices;
	}

	Eigen::Matrix4f* RectangularPrism::getModel() {
		return &this->model;
	}
}


