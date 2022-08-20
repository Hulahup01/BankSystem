#ifndef MY_STRING_H
#define MY_STRING_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class String {
private:
    char* str;
    size_t str_size;

    void clean();

public:
    String();
    String(const char* val);
    String(const char& val);
    String(const String& obj);
    String(String&& obj);


    ~String();

    int length() const;

    const char* c_str() const;

    bool empty();

    char& at(size_t index);
    char& front();
    char& back();
    void swap(String& obj);
    void resize(size_t new_size, char smbl);

    String& operator=(const String& obj);
    String& operator=(String&& obj);
    String operator+(const String& obj);

    friend std::ostream& operator<<(std::ostream& os, const String& obj);

    friend String Strcat(const String& a, const String& b);

};

size_t Strlen(const char* s);

String Strcat(const String& a, const String& b);
char* Strcat(char*& a, const char* b);
char* Strncat(char*& a, const char* b, size_t count);

char* Strcpy(char*& a, char* b);
char* Strcpy(char*& a, const char* b);

char* Strncpy(char*& a, const char* b, size_t count);

int Strcmp(const char* a, const char* b);
int Strncmp(const char* a, const char* b, size_t n);

void* Memcpy(void* a, const void* b, size_t n);
void* Memmove(void* a, const void* b, size_t n);
int Memcmp(void* s1, const void* s2, size_t n);
char* Strtok(char* s1, const char* delim);
void* Memset(void* s, int c, size_t len);

#endif // MY_STRING_H
