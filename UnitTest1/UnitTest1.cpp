#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11_1/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestWriteMinMaxToFile)
		{
			const char* test_file = "test_output.bin";
			int max_odd = 7;
			int min_even = 2;

			WriteMinMaxToFile(test_file, max_odd, min_even);

			ifstream fin(test_file, ios::binary);
			int read_max_odd, read_min_even;
			fin.read((char*)&read_max_odd, sizeof(read_max_odd));
			fin.read((char*)&read_min_even, sizeof(read_min_even));

			Assert::AreEqual(max_odd, read_max_odd);
			Assert::AreEqual(min_even, read_min_even);
		}
	};
}
