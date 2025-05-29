#include "pch.h"
#include "CppUnitTest.h"
#include "../SearchMatrixIdenticalElements/functions.h"
#include <climits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testfindMaxIdenticalSubmatrix
{
    TEST_CLASS(testfindMaxIdenticalSubmatrix)
    {
    public:
        /// @test Матрица содержит только положительные элементы
        TEST_METHOD(PositiveOnly)
        {
            std::vector<std::vector<int>> m = { {1,2,3},{4,5,6},{7,8,9} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"PositiveOnly: rowStart");
            Assert::AreEqual(0, r.colStart, L"PositiveOnly: colStart");
            Assert::AreEqual(0, r.rowEnd, L"PositiveOnly: rowEnd");
            Assert::AreEqual(0, r.colEnd, L"PositiveOnly: colEnd");
            Assert::AreEqual(1, r.size, L"PositiveOnly: size");
        }

        /// @test Матрица содержит только отрицательные элементы
        TEST_METHOD(NegativeOnly)
        {
            std::vector<std::vector<int>> m = { {-1,-1},{-1,-1} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"NegativeOnly: rowStart");
            Assert::AreEqual(0, r.colStart, L"NegativeOnly: colStart");
            Assert::AreEqual(1, r.rowEnd, L"NegativeOnly: rowEnd");
            Assert::AreEqual(1, r.colEnd, L"NegativeOnly: colEnd");
            Assert::AreEqual(4, r.size, L"NegativeOnly: size");
        }

        /// @test Матрица с элементами INT_MIN
        TEST_METHOD(INTMinBounds)
        {
            std::vector<std::vector<int>> m(2, std::vector<int>(2, INT_MIN));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"INTMinBounds: rowStart");
            Assert::AreEqual(0, r.colStart, L"INTMinBounds: colStart");
            Assert::AreEqual(1, r.rowEnd, L"INTMinBounds: rowEnd");
            Assert::AreEqual(1, r.colEnd, L"INTMinBounds: colEnd");
            Assert::AreEqual(4, r.size, L"INTMinBounds: size");
        }

        /// @test Матрица из нулей
        TEST_METHOD(Zeros)
        {
            std::vector<std::vector<int>> m(2, std::vector<int>(2, 0));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"Zeros: rowStart");
            Assert::AreEqual(0, r.colStart, L"Zeros: colStart");
            Assert::AreEqual(1, r.rowEnd, L"Zeros: rowEnd");
            Assert::AreEqual(1, r.colEnd, L"Zeros: colEnd");
            Assert::AreEqual(4, r.size, L"Zeros: size");
        }

        /// @test Произвольная матрица с повторяющимися элементами
        TEST_METHOD(RepeatBlock)
        {
            std::vector<std::vector<int>> m = { {1,2,2},{3,2,2},{4,2,2} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"RepeatBlock: rowStart");
            Assert::AreEqual(1, r.colStart, L"RepeatBlock: colStart");
            Assert::AreEqual(2, r.rowEnd, L"RepeatBlock: rowEnd");
            Assert::AreEqual(2, r.colEnd, L"RepeatBlock: colEnd");
            Assert::AreEqual(6, r.size, L"RepeatBlock: size");
        }

        /// @test Произвольная матрица со средней подматрицей
        TEST_METHOD(CenterBlock)
        {
            std::vector<std::vector<int>> m = { {8,1,4},{2,2,2},{2,2,2} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(1, r.rowStart, L"CenterBlock: rowStart");
            Assert::AreEqual(0, r.colStart, L"CenterBlock: colStart");
            Assert::AreEqual(2, r.rowEnd, L"CenterBlock: rowEnd");
            Assert::AreEqual(2, r.colEnd, L"CenterBlock: colEnd");
            Assert::AreEqual(6, r.size, L"CenterBlock: size");
        }

        /// @test Произвольная матрица с крупной подматрицей
        TEST_METHOD(LargeBlock)
        {
            std::vector<std::vector<int>> m = { {1,3,3,3},{2,3,3,4},{3,3,3,5} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"LargeBlock: rowStart");
            Assert::AreEqual(1, r.colStart, L"LargeBlock: colStart");
            Assert::AreEqual(2, r.rowEnd, L"LargeBlock: rowEnd");
            Assert::AreEqual(2, r.colEnd, L"LargeBlock: colEnd");
            Assert::AreEqual(6, r.size, L"LargeBlock: size");
        }

        /// @test Узкая матрица (ширина=1)
        TEST_METHOD(NarrowMatrix)
        {
            std::vector<std::vector<int>> m = { {1},{1},{1} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"NarrowMatrix: rowStart");
            Assert::AreEqual(0, r.colStart, L"NarrowMatrix: colStart");
            Assert::AreEqual(2, r.rowEnd, L"NarrowMatrix: rowEnd");
            Assert::AreEqual(0, r.colEnd, L"NarrowMatrix: colEnd");
            Assert::AreEqual(3, r.size, L"NarrowMatrix: size");
        }

        /// @test Широкая матрица (ширина=10)
        TEST_METHOD(Wide10)
        {
            std::vector<std::vector<int>> m(3, std::vector<int>(10, 1));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"Wide10: rowStart");
            Assert::AreEqual(0, r.colStart, L"Wide10: colStart");
            Assert::AreEqual(2, r.rowEnd, L"Wide10: rowEnd");
            Assert::AreEqual(9, r.colEnd, L"Wide10: colEnd");
            Assert::AreEqual(30, r.size, L"Wide10: size");
        }

        /// @test Очень широкая матрица (ширина=20)
        TEST_METHOD(VeryWide20)
        {
            std::vector<std::vector<int>> m(2, std::vector<int>(20, 1));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"VeryWide20: rowStart");
            Assert::AreEqual(0, r.colStart, L"VeryWide20: colStart");
            Assert::AreEqual(1, r.rowEnd, L"VeryWide20: rowEnd");
            Assert::AreEqual(19, r.colEnd, L"VeryWide20: colEnd");
            Assert::AreEqual(40, r.size, L"VeryWide20: size");
        }

        /// @test Плоская матрица (высота=1)
        TEST_METHOD(Flat1)
        {
            std::vector<std::vector<int>> m = { {1,1,1} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"Flat1: rowStart");
            Assert::AreEqual(0, r.colStart, L"Flat1: colStart");
            Assert::AreEqual(0, r.rowEnd, L"Flat1: rowEnd");
            Assert::AreEqual(2, r.colEnd, L"Flat1: colEnd");
            Assert::AreEqual(3, r.size, L"Flat1: size");
        }

        /// @test Высокая матрица (высота=10)
        TEST_METHOD(Tall10)
        {
            std::vector<std::vector<int>> m(10, std::vector<int>(1, 1));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"Tall10: rowStart");
            Assert::AreEqual(0, r.colStart, L"Tall10: colStart");
            Assert::AreEqual(9, r.rowEnd, L"Tall10: rowEnd");
            Assert::AreEqual(0, r.colEnd, L"Tall10: colEnd");
            Assert::AreEqual(10, r.size, L"Tall10: size");
        }

        /// @test Очень высокая матрица (высота=20)
        TEST_METHOD(VeryTall20)
        {
            std::vector<std::vector<int>> m(20, std::vector<int>(1, 2));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"VeryTall20: rowStart");
            Assert::AreEqual(0, r.colStart, L"VeryTall20: colStart");
            Assert::AreEqual(19, r.rowEnd, L"VeryTall20: rowEnd");
            Assert::AreEqual(0, r.colEnd, L"VeryTall20: colEnd");
            Assert::AreEqual(20, r.size, L"VeryTall20: size");
        }

        /// @test Одна максимальная подматрица из одинаковых элементов
        TEST_METHOD(SingleMaxBlock)
        {
            std::vector<std::vector<int>> m = { {1,1},{1,1},{2,2} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"SingleMaxBlock: rowStart");
            Assert::AreEqual(0, r.colStart, L"SingleMaxBlock: colStart");
            Assert::AreEqual(1, r.rowEnd, L"SingleMaxBlock: rowEnd");
            Assert::AreEqual(1, r.colEnd, L"SingleMaxBlock: colEnd");
            Assert::AreEqual(4, r.size, L"SingleMaxBlock: size");
        }

        /// @test Две равные по размеру максимальные подматрицы
        TEST_METHOD(TwoEqualMax)
        {
            std::vector<std::vector<int>> m = { {2,2,3},{2,2,3},{3,3,3} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"TwoEqualMax: rowStart");
            Assert::AreEqual(0, r.colStart, L"TwoEqualMax: colStart");
            Assert::AreEqual(1, r.rowEnd, L"TwoEqualMax: rowEnd");
            Assert::AreEqual(1, r.colEnd, L"TwoEqualMax: colEnd");
            Assert::AreEqual(4, r.size, L"TwoEqualMax: size");
        }

        /// @test Подматрица шириной 1
        TEST_METHOD(SubmatrixWidth1)
        {
            std::vector<std::vector<int>> m = { {5,1},{5,2},{5,3} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"SubmatrixWidth1: rowStart");
            Assert::AreEqual(0, r.colStart, L"SubmatrixWidth1: colStart");
            Assert::AreEqual(2, r.rowEnd, L"SubmatrixWidth1: rowEnd");
            Assert::AreEqual(0, r.colEnd, L"SubmatrixWidth1: colEnd");
            Assert::AreEqual(3, r.size, L"SubmatrixWidth1: size");
        }

        /// @test Подматрица шириной 10
        TEST_METHOD(SubmatrixWidth10)
        {
            std::vector<std::vector<int>> m(3, std::vector<int>(10, 4));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"SubmatrixWidth10: rowStart");
            Assert::AreEqual(0, r.colStart, L"SubmatrixWidth10: colStart");
            Assert::AreEqual(2, r.rowEnd, L"SubmatrixWidth10: rowEnd");
            Assert::AreEqual(9, r.colEnd, L"SubmatrixWidth10: colEnd");
            Assert::AreEqual(30, r.size, L"SubmatrixWidth10: size");
        }

        /// @test Подматрица шириной 20
        TEST_METHOD(SubmatrixWidth20)
        {
            std::vector<std::vector<int>> m(1, std::vector<int>(20, 7));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"SubmatrixWidth20: rowStart");
            Assert::AreEqual(0, r.colStart, L"SubmatrixWidth20: colStart");
            Assert::AreEqual(0, r.rowEnd, L"SubmatrixWidth20: rowEnd");
            Assert::AreEqual(19, r.colEnd, L"SubmatrixWidth20: colEnd");
            Assert::AreEqual(20, r.size, L"SubmatrixWidth20: size");
        }

        /// @test Подматрица высотой 1
        TEST_METHOD(SubmatrixHeight1)
        {
            std::vector<std::vector<int>> m = { {1,2,3},{4,4,4},{5,6,7} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(1, r.rowStart, L"SubmatrixHeight1: rowStart");
            Assert::AreEqual(0, r.colStart, L"SubmatrixHeight1: colStart");
            Assert::AreEqual(1, r.rowEnd, L"SubmatrixHeight1: rowEnd");
            Assert::AreEqual(2, r.colEnd, L"SubmatrixHeight1: colEnd");
            Assert::AreEqual(3, r.size, L"SubmatrixHeight1: size");
        }

        /// @test Подматрица высотой 10
        TEST_METHOD(SubmatrixHeight10)
        {
            std::vector<std::vector<int>> m(10, std::vector<int>(10, 9));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"SubmatrixHeight10: rowStart");
            Assert::AreEqual(0, r.colStart, L"SubmatrixHeight10: colStart");
            Assert::AreEqual(9, r.rowEnd, L"SubmatrixHeight10: rowEnd");
            Assert::AreEqual(9, r.colEnd, L"SubmatrixHeight10: colEnd");
            Assert::AreEqual(100, r.size, L"SubmatrixHeight10: size");
        }

        /// @test Подматрица высотой 20
        TEST_METHOD(SubmatrixHeight20)
        {
            std::vector<std::vector<int>> m(20, std::vector<int>(20, 3));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"SubmatrixHeight20: rowStart");
            Assert::AreEqual(0, r.colStart, L"SubmatrixHeight20: colStart");
            Assert::AreEqual(19, r.rowEnd, L"SubmatrixHeight20: rowEnd");
            Assert::AreEqual(19, r.colEnd, L"SubmatrixHeight20: colEnd");
            Assert::AreEqual(400, r.size, L"SubmatrixHeight20: size");
        }

        /// @test Одна максимальная подматрица из положительных элементов размером 10×10 внутри матрицы размером 20×10
        TEST_METHOD(Inside10x10)
        {
            std::vector<std::vector<int>> m;
            m.insert(m.end(), 5, std::vector<int>(10, 0));
            m.insert(m.end(), 10, std::vector<int>(10, 5));
            m.insert(m.end(), 5, std::vector<int>(10, 0));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(5, r.rowStart, L"Inside10x10: rowStart");
            Assert::AreEqual(0, r.colStart, L"Inside10x10: colStart");
            Assert::AreEqual(14, r.rowEnd, L"Inside10x10: rowEnd");
            Assert::AreEqual(9, r.colEnd, L"Inside10x10: colEnd");
            Assert::AreEqual(100, r.size, L"Inside10x10: size");
        }

        /// @test Отрицательная подматрица 5×5 в центре матрицы 10×10
        TEST_METHOD(NegCenter5x5)
        {
            std::vector<std::vector<int>> m;
            m.insert(m.end(), 2, std::vector<int>(5, 0));
            m.insert(m.end(), 5, std::vector<int>(5, -2));
            m.insert(m.end(), 3, std::vector<int>(5, 0));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(2, r.rowStart, L"NegCenter5x5: rowStart");
            Assert::AreEqual(0, r.colStart, L"NegCenter5x5: colStart");
            Assert::AreEqual(6, r.rowEnd, L"NegCenter5x5: rowEnd");
            Assert::AreEqual(4, r.colEnd, L"NegCenter5x5: colEnd");
            Assert::AreEqual(25, r.size, L"NegCenter5x5: size");
        }

        /// @test Квадратная подматрица 3×3 из нулей в матрице 5×5
        TEST_METHOD(Zero3x3In5x5)
        {
            std::vector<std::vector<int>> m = {
                {1,1,1,1,1},
                {1,0,0,0,1},
                {1,0,0,0,1},
                {1,0,0,0,1},
                {1,1,1,1,1}
            };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(1, r.rowStart, L"Zero3x3In5x5: rowStart");
            Assert::AreEqual(1, r.colStart, L"Zero3x3In5x5: colStart");
            Assert::AreEqual(3, r.rowEnd, L"Zero3x3In5x5: rowEnd");
            Assert::AreEqual(3, r.colEnd, L"Zero3x3In5x5: colEnd");
            Assert::AreEqual(9, r.size, L"Zero3x3In5x5: size");
        }

        /// @test Подматрица 2×2 из INT_MAX в матрице 2×2
        TEST_METHOD(INTMax2x2)
        {
            std::vector<std::vector<int>> m(2, std::vector<int>(2, INT_MAX));
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"INTMax2x2: rowStart");
            Assert::AreEqual(0, r.colStart, L"INTMax2x2: colStart");
            Assert::AreEqual(1, r.rowEnd, L"INTMax2x2: rowEnd");
            Assert::AreEqual(1, r.colEnd, L"INTMax2x2: colEnd");
            Assert::AreEqual(4, r.size, L"INTMax2x2: size");
        }

        /// @test Подматрица 1×3 из смешанных элементов
        TEST_METHOD(Mixed1x3)
        {
            std::vector<std::vector<int>> m = { {2,2,3},{2,2,3},{3,3,3},{2,2,2} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"Mixed1x3: rowStart");
            Assert::AreEqual(0, r.colStart, L"Mixed1x3: colStart");
            Assert::AreEqual(1, r.rowEnd, L"Mixed1x3: rowEnd");
            Assert::AreEqual(1, r.colEnd, L"Mixed1x3: colEnd");
            Assert::AreEqual(4, r.size, L"Mixed1x3: size");
        }

        /// @test Единичная матрица 1×1
        TEST_METHOD(OneByOne)
        {
            std::vector<std::vector<int>> m = { {3} };
            Rectangle r = findMaxIdenticalSubmatrix(m);
            Assert::AreEqual(0, r.rowStart, L"OneByOne: rowStart");
            Assert::AreEqual(0, r.colStart, L"OneByOne: colStart");
            Assert::AreEqual(0, r.rowEnd, L"OneByOne: rowEnd");
            Assert::AreEqual(0, r.colEnd, L"OneByOne: colEnd");
            Assert::AreEqual(1, r.size, L"OneByOne: size");
        }
    };
}
