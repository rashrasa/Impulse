#pragma once


namespace PhysicsEngine {
	class Entity {
	public:
		virtual ~Entity() = default;
		virtual void tick(float ms) = 0;
	private:
	};
}