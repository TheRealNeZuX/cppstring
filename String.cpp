#include "String.h"

N::string::string(const char *str, int size): 
    length(size), 
    str(new char[size]) 
    {
        for (int i = 0; i < size; i++) {
            this->str[i] = str[i];
        }
}
N::string::string(const char *str){
    int size = 0;
    while (str[size]!= '\0') {
        ++size;
    }
    this->length = size;
    this->str = new char[size];
    for (int i = 0; i < size; i++) {
        this->str[i] = str[i];
    }
}
N::string::string(const char ch):length(1), str(new char[1]){
    str[0] = ch;
}
N::string::string(const string &str){
    this->length = str.length;
    this->str = new char[this->length];
    for (int i = 0; i < this->length; i++) {
        this->str[i] = str.str[i];
    }
}
N::string& N::string::operator=(const string &str){
    delete[] this->str;
    this->length = str.length;
    this->str = new char[this->length];
    for (int i = 0; i < this->length; i++) {
        this->str[i] = str.str[i];
    }
    return *this;
}
N::string& N::string::operator=(const char *str){
    delete[] this->str;
    int size = 0;
    while (str[size]!= '\0') {
        ++size;
    }
    this->length = size;
    this->str = new char[size];
    for (int i = 0; i < size; i++) {
        this->str[i] = str[i];
    }
    return *this;
}
char& N::string::operator[](int index){
    return str[index];
}
bool N::string::operator==(const string& s1) const{
    return this->str==s1.str;
}
bool N::string::operator!=(const string& s1) const{
    return this->str!=s1.str;
} 
int N::string::size() const {
    return this->length;
}
N::string::~string() {
    delete[] str;
}
const N::string N::operator+(const N::string& s1, const N::string& s2){
    N::string s;
    delete[] s.str;
    s.str = new char[s1.size()+s2.size()];
    for (int i = 0; i < s1.size(); i++)
    {
        s.str[i] = s1.str[i];
    }
    for (int i = 0; i < s2.size()+s1.size(); i++)
    {
        s.str[i+s1.size()] = s2.str[i];
    }
    s.length = s1.size()+s2.size();
    return s;
}
std::ostream& N::operator<<(std::ostream &os, const N::string &s) {
    os<<s.str;
    return os;
}
/*std::istream& N::operator>>(std::istream &is, N::string &s){
    delete[] s.str;
    s.str = new char[100];
    char ch;
    int t = 0;
    while((ch = is.get())!='\n'&&ch != EOF){
        ++t;
        if(t>s.size()){
            char* tmp = new char[s.size()*2];
            for(int i = 0; i < s.size(); ++i){
                tmp[i] = s.str[i];
            }
            delete[] s.str;
            s.str = new char[s.size()*2];
            s.length *= 2;
            delete[] tmp;
        }
        s.str[t] = ch;
    }
    return is;
}*/
std::istream& N::operator>>(std::istream& is, N::string& s) {
    char ch;
    int maxSize = 1000; 
    int currentIndex = 0;
    delete[] s.str;
    s.str = new char[maxSize];
    while ((ch = is.get()) != '\n' && ch != EOF) {
        s.str[currentIndex++] = ch;
        if (currentIndex >= maxSize) {
            maxSize *= 2;
            char* temp = new char[maxSize];
            std::copy(s.str, s.str + currentIndex, temp);
            delete[] s.str;
            s.str = temp;
        }
    }
    s.str[currentIndex] = '\0';
    s.length = currentIndex;
    return is;
}