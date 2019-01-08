// Workshop 9 - Multi-Threading
// SecureData.h
// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-21
#ifndef W9_SECUREDATA_H
#define W9_SECUREDATA_H

#include <iostream>

namespace w9
{
    class Cryptor {
    public:
        char operator()(char in, char key) const { return in ^ key; }
    };
    void converter(char*, char, int, const Cryptor&);
    
    class SecureData {
        char* text;
        std::ostream* ofs;
        int nbytes;
        bool encoded;
        void code(char);
    public:
        SecureData(const char*, char, std::ostream*);
        SecureData(const SecureData&) = delete;
        SecureData& operator=(const SecureData&) = delete;
        ~SecureData();
        void display(std::ostream&) const;
        void backup(const char*);
        void restore(const char*, char);
    };
    std::ostream& operator<<(std::ostream&, const SecureData&);
}
#endif
