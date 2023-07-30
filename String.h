#pragma once
#ifndef String_h
#define String_h
#include <iostream>

namespace N{
    class string{
        private:
            int length;
            char *str;
            friend std::ostream &operator<<(std::ostream &os, const string &s);
            friend std::istream &operator>>(std::istream &is, string &s);
            friend const string operator+(const string& s1, const string &s2);
        public:
            string() = default;
            explicit string(const char *str, int size);
            string(const char *str);
            string(const char ch);
            string(const string &str);
            string &operator=(const string &str);
            string &operator=(const char *str);
            char &operator[](int index);
            //const string operator+(const char* s) const;
            bool operator==(const string& s1) const;
            bool operator!=(const string& s1) const;
            int size() const;
            ~string();
    };
    
    const string operator+(const string& s1, const string& s2);
    std::ostream &operator<<(std::ostream &os, const string &s);
    std::istream &operator>>(std::istream &is, string &s);
}
#endif