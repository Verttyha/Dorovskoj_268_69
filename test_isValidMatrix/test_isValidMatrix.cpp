#include "pch.h"
#include "CppUnitTest.h"
#include "../SearchMatrixIdenticalElements/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testisValidMatrix
{
    TEST_CLASS(testisValidMatrix)
    {
    public:

        /// @test Больше строк, чем maxSize
        TEST_METHOD(TooManyRows)
        {
            std::vector<std::vector<int>> m = { {1,2}, {3,4}, {5,6} };
            Assert::IsFalse(isValidMatrix(m, 2), L"TooManyRows should return false");
        }

        /// @test Больше столбцов, чем maxSize
        TEST_METHOD(TooManyCols)
        {
            std::vector<std::vector<int>> m = { {1,2,3,4} };
            Assert::IsFalse(isValidMatrix(m, 3), L"TooManyCols should return false");
        }

        /// @test Несоответствие длины строк (непрямоугольная)
        TEST_METHOD(NonRectangular)
        {
            std::vector<std::vector<int>> m = { {1,2,3}, {4,5} };
            Assert::IsFalse(isValidMatrix(m, 3), L"NonRectangular should return false");
        }

        /// @test Идеальная квадратная матрица, размер равен maxSize
        TEST_METHOD(PerfectSquare)
        {
            std::vector<std::vector<int>> m = { {1,2}, {3,4} };
            Assert::IsTrue(isValidMatrix(m, 2), L"PerfectSquare should return true");
        }

        /// @test Прямоугольная матрица, строки меньше maxSize
        TEST_METHOD(RectangularRowsLess)
        {
            std::vector<std::vector<int>> m = { {1,2,3}, {4,5,6} };
            Assert::IsTrue(isValidMatrix(m, 4), L"RectangularRowsLess should return true");
        }

        /// @test Единичная матрица 1×1
        TEST_METHOD(SingleCell)
        {
            std::vector<std::vector<int>> m = { {42} };
            Assert::IsTrue(isValidMatrix(m, 1), L"SingleCell should return true");
        }

        /// @test Одна строка, ровно maxSize столбцов
        TEST_METHOD(SingleRowExactCols)
        {
            std::vector<std::vector<int>> m = { {1,2,3,4} };
            Assert::IsTrue(isValidMatrix(m, 4), L"SingleRowExactCols should return true");
        }

        /// @test Одна строка, столбцов меньше maxSize
        TEST_METHOD(SingleRowLessCols)
        {
            std::vector<std::vector<int>> m = { {1,2,3} };
            Assert::IsTrue(isValidMatrix(m, 5), L"SingleRowLessCols should return true");
        }

        /// @test Несколько строк, строк меньше maxSize, столбцы равны
        TEST_METHOD(MultiRowsColsEqual)
        {
            std::vector<std::vector<int>> m = { {1,2}, {3,4}, {5,6} };
            Assert::IsTrue(isValidMatrix(m, 3), L"MultiRowsColsEqual should return true");
        }
    };
}
