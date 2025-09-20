#pragma once
#include "entity.h"

namespace PhysicsEngine {
    class Sphere : public PhysicsEngine::Entity {
    private:

    public:
        Eigen::Vector3f position;
        Eigen::Vector3f velocity;
        Eigen::Vector3f acceleration;

        Eigen::Matrix4f model;
        // TODO: Implement way to represent spheres
        float vertices[1];
        unsigned int nVertices;

        unsigned int indices[1];
        unsigned int nIndices;

        double radius;

        Sphere(Eigen::Vector3f position, double radius);
        ~Sphere();

        void tick(float ms);

        float* getVertices();
        unsigned int* getIndices();
        Eigen::Matrix4f* getModel();
    };
}