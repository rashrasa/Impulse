struct Matrix2F {
	float a;
	float b;
	float c;
	float d;

	Matrix2F operator+ (Matrix2F other) {
		return Matrix2F{
			this->a + other.a,
			this->b + other.b,
			this->c + other.c,
			this->d + other.d,

		};
	}

	Matrix2F operator- (Matrix2F other) {
		return Matrix2F{
			this->a - other.a,
			this->b - other.b,
			this->c - other.c,
			this->d - other.d,

		};
	}

	Matrix2F operator* (Matrix2F other) {
		return Matrix2F{
			this->a * other.a + this->b * other.c,
			this->a * other.b + this->b * other.d,
			this->c * other.a + this->d * other.c,
			this->c * other.b + this->d * other.d,
		};
	}

	float det() const {
		return this->a * this->d - this->b * this->c;
	}
};