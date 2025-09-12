#include "pch.h"
#include "framework.h"

#include <Eigen/Dense>
#include "entity.h"


class Rectangle: public PhysicsEngine::Entity {
public:
	Eigen::Vector3f position;
	Eigen::Vector3f velocity;
	Eigen::Vector3f acceleration;

	float length;
	float width;
};