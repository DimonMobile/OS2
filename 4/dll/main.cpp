extern "C"
{
	__declspec(dllexport) int mult(int a, int b)
	{
		return a * b;
	}

	__declspec(dllexport) double divide(double a, double b)
	{
		return a / b;
	}

	__declspec(dllexport) int sum(int a, int b)
	{
		return a + b;
	}
}