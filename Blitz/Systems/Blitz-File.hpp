#pragma once

#include "../Blitz-Core.hpp"

namespace Blitz {
    class File {
    public:
        File();
        ~File();

        void Load(const char* filename);
        void Save(const char* filename, std::string data);

        std::string GetDataFromLine(uint line);
        size_t FindInLine(std::string word, uint line);

    private:
        std::vector<std::string> m_data;

    };
};