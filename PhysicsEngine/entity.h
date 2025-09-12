#pragma once


namespace PhysicsEngine {
	class Entity {
	public:
		virtual void tick(float ms) = 0;
	private:
	};
}