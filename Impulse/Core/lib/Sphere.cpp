#include "Impulse/Core/Sphere.h"

namespace Impulse::Core {
    Sphere::Sphere(Eigen::Vector3f position, double radius) :vertices{ 0.0f } {
        this->radius = radius;
        this->position = position;
        this->velocity << 0, 0, 0;
        this->acceleration << 0, 0, 0;
    }
    Sphere::~Sphere() {

    };
    void Sphere::tick(float ms) {
        // TODO: Implement
    }

    float* Sphere::getVertices() {
        return this->vertices;
    }

    unsigned int* Sphere::getIndices() {
        return this->indices;
    }
    Eigen::Matrix4f* Sphere::getModel() {
        return &this->model;
    }

}