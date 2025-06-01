#include "functions.h"
#include "errors.h"
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief ���������� ������� ����� ����� � ����.
 *
 * ������ ��� ������� ��������� �� ��������� ������, �������� ����������� ���������.
 *
 * @param matrix ����������� ������ ����� ����� ��� ������.
 * @param filename ���� � ��������� �����.
 * @throws Error ��� ������������� ������� ��� �������� ����.
 */
void writeMatrixToFile(const std::string& filename, const std::vector<std::vector<int>>& matrix) {
    std::ofstream file(filename); ///< �������� ���� �� ������
    if (!file.is_open()) {
        throw Error(ErrorType::outFileCreateFail, "", filename); ///< ������: �� ������� ������� ����
    }

    for (const auto& row : matrix) {
        for (std::size_t j = 0; j < row.size(); ++j) {
            file << row[j]; ///< ��������� �������
            if (j + 1 < row.size()) {
                file << ' '; ///< �������� ��������, ����� ����������
            }
        }
        file << '\n'; ///< �������� ������
    }
}