#include "functions.h"
#include "errors.h"
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief ��������� ��� ������ �� ���������� �����.
 * @param fileName ���� � ����� ��� ������.
 * @return ������ �����: ������ ������ ����� ��� ��������� �������.
 * @throws Error ��� ������������� ������� ����.
 */
std::vector<std::string> readLinesFromFile(const std::string& fileName) {
    std::ifstream file(fileName); ///< �������� ���� �� ������
    if (!file.is_open()) {
        throw Error(ErrorType::inFileNotExist, "", fileName); ///< ������: ���� �� ������ ��� �� ������
    }

    std::vector<std::string> lines; ///< ���������: ������ �����
    std::string line;
    while (std::getline(file, line)) { ///< ����� ���������
        lines.push_back(line); ///< �������� ������ � ������
    }
    return lines;
}
