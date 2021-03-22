#include "Blitz-File.hpp"

namespace Blitz {
    File::File() { }
        
    File::~File() {
        delete this;
    }

    void File::Load(const char* filename) {
        std::string line;
        std::ifstream file(filename);
        if(file.is_open()) {
            while(std::getline(file, line)) {
                m_data.push_back(line);
                std::cout << line << "\n";
            }
            file.close();
        }
    }
        
    void File::Save(const char* filename, std::string data) {
        std::ofstream file(filename);
        if(file.is_open()) {
            file << data;
            file.close();
        }
    }

    std::string File::GetDataFromLine(uint line) {
        if(line >= m_data.size()) {
            return std::string("NULL");
        } else if(line < 0) {
            return std::string("NULL");
        } else {
            return m_data.at(line);
        }
    }

    size_t File::FindInLine(std::string word, uint line) {
        return GetDataFromLine(line).find(word);
    }
};