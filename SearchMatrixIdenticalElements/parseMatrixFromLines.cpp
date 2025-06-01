#include "functions.h"
#include "errors.h"
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief ����������� ������ ������ � ������� ����� �����.
 *
 * ������ ������ ������ ��������� �����, ���������� ���������.
 * ������ ������ ������������.
 *
 * @param lines ������ �����, ������ �� ������� ������������ ����� ������ �������.
 * @return ����������� ������ ����� ����� � ���������� �������.
 * @throws Error ��� �������� ������� ������ ��� ���� ������� �� �������������.
 */
std::vector<std::vector<int>> parseMatrixFromLines(const std::vector<std::string>& lines) {
    if (lines.empty()) {
        throw Error(ErrorType::emptyFile);
    }

    std::vector<std::vector<int>> matrix;
    int expectedCols = -1; ///< ���������� ��������, ��������� �� ���� �������


    for (const auto& line : lines) {
        if (line.empty()) {
            throw Error(ErrorType::emptyLine);
        }

        std::istringstream iss(line); ///< �������� ������ �� �����
        std::vector<int> row;
        int value;
        while (iss >> value) {
            row.push_back(value); ///< �������� �������� � ������
        }

        if (iss.fail() && !iss.eof()) {
            throw Error(ErrorType::invalidSymbol, "�������� ������ �����", ""); ///< ������: ���������� ������
        }

        if (expectedCols < 0) {
            expectedCols = static_cast<int>(row.size()); ///< ��������� ���������� �������� � ������ ������
        }

        if (row.empty() || static_cast<int>(row.size()) != expectedCols) {
            throw Error(ErrorType::notRectangular, "������������ ����� ��������", ""); ///< ������: ������ ������ �����
        }

        matrix.push_back(row); ///< �������� ������ � �������
    }

    return matrix;
}