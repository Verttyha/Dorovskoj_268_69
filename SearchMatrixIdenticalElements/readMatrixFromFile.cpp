#include "functions.h"
#include "errors.h"
#include <vector>
#include <string>

/**
 * @brief ��������� � ��������� ������� ����� ����� �� �����.
 *
 * @param filename ���� � �������� �����.
 * @param matrix  �������������� �������.
 * @throws Error ��� ������� ������, �������� ��� ������������ ���������.
 */
void readMatrixFromFile(const std::string& filename, std::vector<std::vector<int>>& matrix) {
    auto lines = readLinesFromFile(filename);
    matrix = parseMatrixFromLines(lines);
}