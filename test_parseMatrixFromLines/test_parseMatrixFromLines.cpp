#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include "../SearchMatrixIdenticalElements/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testparseMatrixFromLines
{
    TEST_CLASS(testparseMatrixFromLines)
    {
    public:

        /// @test Проверяет, что при пустом векторе строк выбрасывается исключение ErrorType::emptyFile
        TEST_METHOD(EmptyVectorThrows)
        {
            Assert::ExpectException<Error>([] { parseMatrixFromLines({}); }, L"Should throw emptyFile");
        }

        /// @test Проверяет, что при наличии пустой строки выбрасывается исключение ErrorType::emptyLine
        TEST_METHOD(ContainsEmptyLineThrows)
        {
            Assert::ExpectException<Error>([] { parseMatrixFromLines({ "1 2 3", "", "4 5 6" }); }, L"Should throw emptyLine");
        }

        /// @test Проверяет, что при наличии недопустимого символа выбрасывается ErrorType::invalidSymbol
        TEST_METHOD(InvalidSymbolThrows)
        {
            Assert::ExpectException<Error>([] { parseMatrixFromLines({ "1 2 3", "4 a 6" }); }, L"Should throw invalidSymbol");
        }

        /// @test Проверяет, что при наличии символов рядом с числом выбрасывается ErrorType::invalidSymbol
        TEST_METHOD(SymbolAttachedToNumberThrows)
        {
            Assert::ExpectException<Error>([] { parseMatrixFromLines({ "1 2 3", "4 5x 6" }); }, L"Should throw invalidSymbol");
        }

        /// @test Проверяет, что при значении вне диапазона int выбрасывается ErrorType::outOfRange
        TEST_METHOD(NumberOutOfRangeThrows)
        {
            Assert::ExpectException<Error>([] { parseMatrixFromLines({ "1 2", "9999999999999999999999" }); }, L"Should throw outOfRange");
        }

        /// @test Проверяет, что при разной длине строк выбрасывается ErrorType::notRectangular
        TEST_METHOD(DifferentLengthRowsThrows)
        {
            Assert::ExpectException<Error>([] { parseMatrixFromLines({ "1 2 3", "4 5", "6 7 8" }); }, L"Should throw notRectangular");
        }

        /// @test Проверка корректной матрицы 10x10 положительных чисел
        TEST_METHOD(ValidMatrix10x10Positive)
        {
            std::vector<std::string> input;
            for (int i = 0; i < 10; ++i)
                input.push_back("1 2 3 4 5 6 7 8 9 10");

            std::vector<std::vector<int>> expected(10, std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"ValidMatrix10x10Positive: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Проверка корректной матрицы 10x10 отрицательных чисел
        TEST_METHOD(ValidMatrix10x10Negative)
        {
            std::vector<std::string> input;
            for (int i = 0; i < 10; ++i)
                input.push_back("-1 -2 -3 -4 -5 -6 -7 -8 -9 -10");

            std::vector<std::vector<int>> expected(10, std::vector<int>{-1, -2, -3, -4, -5, -6, -7, -8, -9, -10});
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"ValidMatrix10x10Negative: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Проверка граничных значений int
        TEST_METHOD(IntMinMaxAlternating)
        {
            std::string line;
            for (int i = 0; i < 10; ++i) {
                line += std::to_string(i % 2 == 0 ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max());
                line += " ";
            }
            std::vector<std::string> input(2, line);

            std::vector<int> row;
            for (int i = 0; i < 10; ++i)
                row.push_back(i % 2 == 0 ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max());

            std::vector<std::vector<int>> expected(2, row);
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"IntMinMaxAlternating: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Проверка матрицы 1x5 из нулей
        TEST_METHOD(Matrix1x5Zeroes)
        {
            std::vector<std::string> input = { "0", "0", "0", "0", "0" };
            std::vector<std::vector<int>> expected = { {0},{0},{0},{0},{0} };
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"Matrix1x5Zeroes: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Матрица любых значений 5×5
        TEST_METHOD(Matrix5x5Test1)
        {
            std::vector<std::string> input = {
                "1 2 3 4 5",
                "6 7 8 9 10",
                "11 12 13 14 15",
                "16 17 18 19 20",
                "21 22 23 24 25"
            };
            std::vector<std::vector<int>> expected = {
                {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}
            };
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"Matrix5x5Test1: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Матрица любых значений 5×5
        TEST_METHOD(Matrix5x5Test2)
        {
            std::vector<std::string> input = {
                "5 4 3 2 1",
                "10 9 8 7 6",
                "15 14 13 12 11",
                "20 19 18 17 16",
                "25 24 23 22 21"
            };
            std::vector<std::vector<int>> expected = {
                {5,4,3,2,1}, {10,9,8,7,6}, {15,14,13,12,11}, {20,19,18,17,16}, {25,24,23,22,21}
            };
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"Matrix5x5Test2: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Матрица любых значений 5×5
        TEST_METHOD(Matrix5x5Test3)
        {
            std::vector<std::string> input = {
                "10 0 -5 3 7",
                "-1 -2 -3 -4 -5",
                "100 200 300 400 500",
                "-100 -200 -300 -400 -500",
                "42 42 42 42 42"
            };
            std::vector<std::vector<int>> expected = {
                {10,0,-5,3,7}, {-1,-2,-3,-4,-5}, {100,200,300,400,500}, {-100,-200,-300,-400,-500}, {42,42,42,42,42}
            };
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"Matrix5x5Test3: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Матрица шириной 1 и высотой 10, положительные числа
        TEST_METHOD(Matrix1x10Positive)
        {
            std::vector<std::string> input;
            std::vector<std::vector<int>> expected;
            for (int i = 1; i <= 10; ++i) {
                input.push_back(std::to_string(i));
                expected.push_back({ i });
            }
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"Matrix1x10Positive: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Матрица шириной 10 и высотой 1, отрицательные числа
        TEST_METHOD(Matrix10x1Negative)
        {
            std::string line;
            std::vector<int> expectedRow;
            for (int i = 1; i <= 10; ++i) {
                line += std::to_string(-i) + " ";
                expectedRow.push_back(-i);
            }
            std::vector<std::vector<int>> expected = { expectedRow };
            auto actual = parseMatrixFromLines({ line });
            Assert::IsTrue(expected == actual, L"Matrix10x1Negative: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Матрица 1x20 с чередованием INT_MIN и INT_MAX
        TEST_METHOD(Matrix1x20AlternatingLimits)
        {
            std::string line;
            std::vector<int> expectedRow;
            for (int i = 0; i < 20; ++i) {
                int val = (i % 2 == 0) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
                line += std::to_string(val) + " ";
                expectedRow.push_back(val);
            }
            std::vector<std::vector<int>> expected = { expectedRow };
            auto actual = parseMatrixFromLines({ line });
            Assert::IsTrue(expected == actual, L"Matrix1x20AlternatingLimits: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Матрица 1x20 из нулей
        TEST_METHOD(Matrix1x20Zeroes)
        {
            std::vector<std::string> input(20, "0");
            std::vector<std::vector<int>> expected(20, std::vector<int>{0});
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"Matrix1x20Zeroes: возвращённая матрица не совпадает с ожидаемой");
        }

        /// @test Матрица 10x20 с произвольными значениями
        TEST_METHOD(Matrix10x20Random)
        {
            std::vector<std::string> input;
            std::vector<std::vector<int>> expected;
            for (int i = 0; i < 20; ++i) {
                std::string line;
                std::vector<int> row;
                for (int j = 1; j <= 10; ++j) {
                    line += std::to_string(i * 10 + j) + " ";
                    row.push_back(i * 10 + j);
                }
                input.push_back(line);
                expected.push_back(row);
            }
            auto actual = parseMatrixFromLines(input);
            Assert::IsTrue(expected == actual, L"Matrix10x20Random: возвращённая матрица не совпадает с ожидаемой");
        }
    };
}