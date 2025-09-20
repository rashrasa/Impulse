#include "sphere.h"

namespace PhysicsEngine {
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

    unsigned int Sphere::getNumVertices() {
        return this->nVertices;
    }

    float* Sphere::getIndices() {
        return this->indices;
    }

    unsigned int Sphere::getNumIndices() {
        return this->nIndices;
    }
}