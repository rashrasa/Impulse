#include "pch.h"
#include "framework.h"

#include <Eigen/Dense>
#include <iostream>

#include "rectangular_prism.h"

namespace PhysicsEngine {
	void RectangularPrism::tick(float ms) {
		// TODO
	}
	RectangularPrism::RectangularPrism() {
		this->position << 0, 0, 0;
		this->velocity << 0, 0, 0;
		this->acceleration << 0, 0, 0;
		this->height = 1;
		this->length = 1;
		this->width = 1;
	}
	RectangularPrism::RectangularPrism(Eigen::Vector3f position) {
		this->position = position;
		this->velocity << 0, 0, 0;
		this->acceleration << 0, 0, 0;
		this->height = 1;
		this->length = 1;
		this->width = 1;
	}
	RectangularPrism::~RectangularPrism() {
		std::cout << "Deleted object\n";
	}
}


