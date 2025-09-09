struct Vector2F {
	float x;
	float y;


	Vector2F operator+ (Vector2F other) {
		return Vector2F{
			this->x + other.x,
			this->y + other.y,
		};
	}
	Vector2F operator- (Vector2F other) {
		return Vector2F{
			this->x - other.x,
			this->y - other.y,
		};
	}
	float dot(Vector2F other) const {
		return this->x * other.x + this->y * other.y;
	}

	// TODO: Implement cross product
};