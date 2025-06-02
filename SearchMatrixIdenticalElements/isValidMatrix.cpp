#include "functions.h"
#include <vector>


/**
 * @brief ���������, �������� �� �������� ������� ���������� (�� ������ � ��� ������ ����� ���������� ����� ��������).
 * @param matrix ����������� ������ ����� �����, �������������� �������.
 * @return true, ���� ������� ���������; false � � ��������� ������.
 */

bool isValidMatrix(const std::vector<std::vector<int>>& matrix, int maxSize) {
    if (matrix.empty()) {
        return false;  ///< ������� ����� � �����������.
    }
    if (static_cast<int>(matrix.size()) > maxSize) {
        return false;  ///< ����� ����� ��������� ���������� ������.
    }

    std::size_t numCols = matrix[0].size();  ///< ���������� �������� � ������ ������.
    if (numCols == 0 || static_cast<int>(numCols) > maxSize) {
        return false;  ///< ������� ������ ��� ���������� ��������� � ������� �����������.
    }

    for (const auto& row : matrix) {
        if (row.size() != numCols) {
            return false;  ///< ������� ������ � �������� ������ �������� � ������� �����������.
        }
    }

    return true;  ///< ��� �������� �������� � ������� ���������.
}