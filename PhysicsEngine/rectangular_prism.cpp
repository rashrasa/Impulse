#include "pch.h"
#include "framework.h"

#include <Eigen/Dense>
#include "entity.h"
#include <iostream>


class RectangularPrism : public PhysicsEngine::Entity {
public:
	Eigen::Vector3f position;
	Eigen::Vector3f velocity;
	Eigen::Vector3f acceleration;
	float length;
	float width;
	float height;

	void tick(float ms) {
		// TODO
	}

	RectangularPrism() {
		this->height = 1;
		this->length = 1;
		this->width = 1;
	}
	~RectangularPrism() {
		std::cout << "Deleted object\n";
	}

};
