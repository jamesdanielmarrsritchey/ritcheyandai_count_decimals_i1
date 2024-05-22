#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 5 || (std::string(argv[1]) != "--max_decimal") || (std::string(argv[3]) != "--file")) {
        std::cerr << "Usage: " << argv[0] << " --max_decimal <max_decimal> --file <file>\n";
        return 1;
    }

    int max_decimal = std::stoi(argv[2]);
    std::string filename = argv[4];
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    int count = 0;
    char byte;
    while (file.read(&byte, 1)) {
        if (static_cast<unsigned char>(byte) <= max_decimal) {
            ++count;
        }
    }

    file.close();
    std::cout << count << '\n';
    return 0;
}