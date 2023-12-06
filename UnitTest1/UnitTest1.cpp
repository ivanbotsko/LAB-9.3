#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 9.3/PR 9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(EmployeeTests)
{
public:
    TEST_METHOD(SearchEmployee_NonExistingEmployee_ReturnsMinusOne)
    {
        const int N = 3;
        Employee* p = new Employee[N];
        p[0] = { "Яворський", "І.І.", "Java розробник", 2020, 2000.0 };
        p[1] = { "Мельник", "П.П.", "Python розробник", 2019, 1600.0 };
        p[2] = { "Ільницький", "С.С.", "С++ розробник", 2021, 1800.0 };

        int result = SearchEmployee(p, N, "undefined");

        Assert::AreEqual(-1, result);

        delete[] p;
    }
};
