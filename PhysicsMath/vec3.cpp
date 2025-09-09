struct Vector3F {
	float x;
	float y;
	float z;


	Vector3F operator+ (Vector3F other) {
		return Vector3F{
			this->x + other.x,
			this->y + other.y,
			this->z + other.z
		};
	}
	Vector3F operator- (Vector3F other) {
		return Vector3F{
			this->x - other.x,
			this->y - other.y,
			this->z - other.z
		};
	}
	float dot(Vector3F other) const {
		return this->x * other.x + this->y * other.y + this->z * other.z;
	}

	// TODO: Implement cross product
};