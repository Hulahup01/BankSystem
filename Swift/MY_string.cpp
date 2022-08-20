#define _CRT_SECURE_NO_WARNINGS
#include "MY_string.h"

String::String() : str(nullptr), str_size(0) {
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* val) {
    if (val == nullptr) {
        String();
    }
    else {
        str_size = Strlen(val);
        str = new char[str_size + 1];
        Strcpy(str, val);
        str[Strlen(val)] = '\0';
    }
}

String::String(const char& val) : str_size(1) {
    str = new char[str_size + 1];
    str[0] = val;
    str[1] = '\0';
}

String::String(const String& obj) { // copy
    str_size = obj.str_size;
    str = new char[str_size + 1];
    Strcpy(str, obj.str);
    str[str_size] = '\0';
}

String::String(String&& obj) { // move
    clean();
    str_size = obj.str_size;
    str = obj.str;
    obj.str = nullptr;
}

String::~String() {
    clean();
}

int String::length() const{
    return static_cast<int>(str_size);
}

void String::clean() {
    if (str != nullptr)
        delete[] str;
    str_size = 0;
}

const char* String::c_str() const{
    return str;
}

bool String::empty() {
    return str_size == 0;
}

char& String::front() {
    return str[0];
}

char& String::back() {
    return str[str_size - 1];
}

char& String::at(size_t index) {
    if (!(index > str_size - 1))
        return str[index];
}

void String::swap(String& obj) {
    String temp{ obj };
    obj = *this;
    *this = temp;
}

void String::resize(size_t new_size, char smbl) {
    char* new_str = new char[new_size + 1];

    if (new_size <= str_size) {
        str_size = new_size;
        for (size_t i = 0; i < str_size; i++) {
            new_str[i] = str[i];
        }
    }
    else {
        for (size_t i = 0; i < str_size; i++) {
            new_str[i] = str[i];
        }
        for (size_t i = str_size; i < new_size; i++) {
            new_str[i] = smbl;
        }
    }

    str_size = new_size;
    new_str[str_size] = '\0';

    delete[] str;
    str = new_str;
}

String& String::operator=(const String& obj) {
    if (this == &obj)
        return *this;

    clean();
    str_size = obj.str_size;
    str = new char[str_size + 1];
    Strcpy(str, obj.str);

    return *this;
}

String& String::operator=(String&& obj) {
    clean();
    str_size = obj.str_size;
    str = obj.str;
    obj.str = nullptr;

    return *this;
}

String String::operator+(const String& obj) {

    String new_str;
    new_str.str_size = str_size + obj.str_size;
    new_str.str = new char[new_str.str_size + 1];

    int j = 0;
    for (size_t i = 0; i < str_size; i++) {
        new_str.str[j++] = str[i];
    }
    for (size_t i = 0; i < obj.str_size; i++) {
        new_str.str[j++] = obj.str[i];
    }

    new_str.str[new_str.str_size] = '\0';

    return new_str;
}

std::ostream& operator<<(std::ostream& os, const String& obj){
    os << obj.str;
    return os;
}

size_t Strlen(const char* s) {
    size_t count = 0;
    for (int i = 0; s[i] != '\0'; i++)
        count++;

    return count;
}

String Strcat(const String& a, const String& b) {
    String new_str;
    new_str.str_size = a.str_size + b.str_size;
    new_str.str = new char[new_str.str_size + 1];

    int j = 0;
    for (size_t i = 0; i < a.str_size; i++) {
        new_str.str[j++] = a.str[i];
    }
    for (size_t i = 0; i < b.str_size; i++) {
        new_str.str[j++] = b.str[i];
    }

    new_str.str[new_str.str_size] = '\0';

    return new_str;
}

char* Strcat(char*& a, const char* b) {
    //if (a == nullptr || b == nullptr)
        //throw std::exception("Pointer is nullptr!");

    size_t size_a = Strlen(a);
    size_t size_b = Strlen(b);
    char* temp = new char[size_a + size_b + 1];

    Strcpy(temp, a);

    for (size_t i = 0; i < size_b; i++) {
        temp[size_a++] = b[i];
    }
    temp[size_a] = '\0';
    a = temp;

    return a;
}
char* Strncat(char*& a, const char* b, size_t count) {
   // if (a == nullptr || b == nullptr)
     //   throw std::exception("Pointer is nullptr!");

    if (count == 0)
        return a;

    size_t size_a = Strlen(a);
    size_t size_b = Strlen(b);

    if (count > size_b)
        count = size_b;

    char* temp = new char[size_a + count + 1];

    Strcpy(temp, a);

    for (size_t i = 0; i < count; i++) {
        temp[size_a++] = b[i];
    }
    temp[size_a] = '\0';
    a = temp;

    return a;
}

char* Strcpy(char*& a, char* b) {
    //if (a == nullptr || b == nullptr)
     //   throw::std::exception("Argument is nullptr!");

    if (a == b)
        return a;

    if (Strlen(a) < Strlen(b)) {
        a = new char[Strlen(b) + 1];
    }
    size_t i;
    for (i = 0; i < Strlen(b); i++) {
        a[i] = b[i];
    }
    a[i] = '\0';

    return a;
}

char* Strcpy(char*& a, const char* b) {
    //if (a == nullptr || b == nullptr)
      //  throw::std::exception("Argument is nullptr!");

    if (a == b)
        return a;

    if (Strlen(a) < Strlen(b)) {
        a = new char[Strlen(b) + 1];
    }
    size_t i;
    for (i = 0; i < Strlen(b); i++) {
        a[i] = b[i];
    }
    a[i] = '\0';

    return a;
}

char* Strncpy(char*& a, const char* b, size_t count) {

    if (count <= 0) {
        return a;
    }
    if (count > Strlen(b))
        count = Strlen(b);

    if (Strlen(a) < count) {
        char* temp = new char[count + 1];
        a = temp;
    }
    size_t i;
    for (i = 0; i < count; i++) {
        a[i] = b[i];
    }
    a[i] = '\0';

    return a;
}

int Strcmp(const char* a, const char* b) {
    //if (a == nullptr || b == nullptr)
      //  throw std::exception("Pointer is nullptr!");

    size_t size_a = Strlen(a);
    size_t size_b = Strlen(b);

    if (size_a < size_b)
        return -1;

    if (size_a > size_b)
        return 1;

    for (size_t i = 0; i < size_a; i++) {
        if (a[i] < b[i])
            return -1;
        if (a[i] > b[i])
            return 1;
    }

    return 0;
}
int Strncmp(const char* a, const char* b, size_t n) {
    //if (a == nullptr || b == nullptr || n == 0)
      //  throw std::exception("Pointer is nullptr or n == 0!");

    size_t size_a = Strlen(a);
    size_t size_b = Strlen(b);

    size_t min_size = size_a;
    if (size_b < size_a)
        min_size = size_b;

    if (min_size < n)
        n = min_size;

    for (size_t i = 0; i < n; i++) {
        if (a[i] < b[i])
            return -1;
        if (a[i] > b[i])
            return 1;
    }

    return 0;
}

void* Memcpy(void* a, const void* b, size_t n){
    char* aDest = static_cast<char*>(a);
    const char* bSource = static_cast<const char*>(b);

    if ((aDest != nullptr) && (bSource != nullptr))
    {
        while (n) //till cnt
        {
            //Copy byte by byte
            *(aDest++) = *(bSource++);
            --n;
        }
    }
    return a;
}

void* Memmove(void* a, const void* b, size_t n){
    char* pa = static_cast<char*>(a);
    const char* pb = static_cast<const char*>(b);

    char* tmp = new char[(sizeof(char)* n)];
    if (tmp == nullptr)
        return nullptr;

    // copy src to tmp array
    for (size_t i = 0; i < n; ++i){
       *(tmp + i) = *(pb + i);
    }
    //copy tmp to dest
    for (size_t i = 0; i < n; ++i){
        *(pa + i) = *(tmp + i);
    }

    delete[] tmp;

    return a;
}

int Memcmp(void* s1, const void* s2, size_t n){
    char* p = static_cast<char*>(s1);
    const char* q = static_cast<const char*>(s2);

    size_t min_len = Strlen(p);
    if (Strlen(q) < min_len)
        min_len = Strlen(q);


    if (n > min_len)
        n = min_len;

    int charCompareStatus = 0;
    if (s1 == s2)
        return charCompareStatus;

    while (min_len > 0){
        if (*p != *q){
            charCompareStatus = (*p > *q) ? 1 : -1;
            break;
        }
        min_len--;
        p++;
        q++;
    }
    return charCompareStatus;
}

bool is_delim(char c, const char* delim){
    while (*delim != '\0'){
        if (c == *delim)
            return true;
        delim++;
    }
    return false;
}

char* Strtok(char* s1, const char* delim){
    static char* p; // start of the next search
    if (!s1)
        s1 = p;

    while (true) {
        if (is_delim(*s1, delim)) {
            s1++;
            continue;
        }
        if (*s1 == '\0') {
            return nullptr;
        }

        break;
    }
    char* ret = s1;
    while (true) {
        if (*s1 == '\0') {
            p = s1;
            return ret;
        }
        if (is_delim(*s1, delim)) {
            *s1 = '\0';
            p = s1 + 1;
            return ret;
        }
        s1++;
    }
}
void* Memset(void* s, int c, size_t len){
    char* p = static_cast<char*>(s);

    if (len > Strlen(p))
        len = Strlen(p);

    while (len--)
        *p++ = (unsigned char)c;

    return s;
}
