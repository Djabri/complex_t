#include <iostream>

struct complex_t
{
	float real;
	float imag;

	complex_t();

	complex_t add(complex_t other) const;
	complex_t sub(complex_t other) const;
	complex_t mul(complex_t other) const;
	complex_t div(complex_t other) const;

	std::istream& read(std::istream & stream) {
		// (3, 4)
		char op;

		float aReal, aImag;
		if (stream >> op && op == '(' &&
			stream >> aReal && stream >> op &&
			op == ',' && stream >> aImag &&
			stream >> op && op == ')') {
			real = aReal;
			imag = aImag;
		}
		else {
			stream.setstate(std::ios_base::failbit); // failbit, записи на извлечение допустимого поля из потока
		}

		return stream;
	}
	std::ostream& write(std::ostream& stream) {
		// (3, 4)
		stream << '(' << real << ", " << imag << ')';
		return stream;
	}
};

complex_t::complex_t() : real(0.0f), imag(0.0f)
{

}

complex_t complex_t::add(complex_t other) const
{
	complex_t res;
	res.real = real + other.real;
	res.imag = imag + other.imag;
	return res;
}

complex_t complex_t::sub(complex_t other) const
{
	complex_t res;
	res.real = real - other.real;
	res.imag = imag - other.imag;
	return res;
}

complex_t complex_t::mul(complex_t other) const
{
	complex_t result;
	result.real = (real * other.real) - (imag * other.imag);
	result.imag = (imag  * other.real) + (other.imag * real);
	return result;
}

complex_t complex_t::div(complex_t other) const
{
	complex_t result;
	result.real = ((real * other.real) + (imag * other.imag)) / ((other.real * other.real) + (other.imag * other.imag));
	result.imag = ((imag * other.real) - (real * other.imag)) / ((other.real * other.real) + (other.imag * other.imag));
	return result;
}


int main()
{

	char str;

	complex_t a;
	complex_t b;

	a.read(std::cin);
	b.read(std::cin);

	a.add(b).write(std::cout);

	system("pause");
	return 0;
}