//
// Created by Hugo-PC on 24/5/2022.
//
#include <iostream>
#include <climits>
#include "mystring.h"

size_t strlen(const char *s);

using namespace std;

//默认构造函数
Mystring::Mystring() {
    m_data = new char[1];
    *m_data = '\0';
}

//值传递构造函数
Mystring::Mystring(const char *s) {
    if (s == nullptr) {
        m_data = new char[1];
        *m_data = '\0';
    } else {
        int length = strlen(s);
        m_data = new char[length + 1];
        strcpy(m_data, s);
    }
}

//拷贝构造函数
Mystring::Mystring(const Mystring &source) {

    int length = strlen(source.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, source.m_data);
    std::cout << "copy constructor called, new m_data is" << m_data << std::endl;
}


//重载输出运算符
std::ostream &operator<<(std::ostream &os, const Mystring &s) {
    os << s.m_data;
    return os;
}

//重载输入运算符
std::istream &operator>>(std::istream &is, Mystring &s) {
    is >> s.m_data;
    return is;
}

//实现memcpy
void *Mystring::memcpy(void *destination, const void *source, size_t num) {
    char *d = (char *) destination;
    char *s = (char *) source;
    for (int i = 0; i < num; i++) {
        d[i] = s[i];
    }
    return destination;
}

//实现memmove
void *memmove(void *destination, const void *source, size_t num) {
    char *d = (char *) destination;
    char *s = (char *) source;
    if (d < s) {
        for (int i = 0; i < num; i++) {
            d[i] = s[i];
        }
    } else {
        for (int i = num - 1; i >= 0; i--) {
            d[i] = s[i];
        }
    }
    return destination;
}

//实现strcpy
char *Mystring::strcpy(char *cpy, const char *src) {
    int i = 0;
    //拷贝原字符串到目标字符串
    while (src[i] != '\0') {
        cpy[i] = src[i];
        i++;
    }
    cpy[i] = '\0';
    return cpy;
}

size_t Mystring::strlen(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

//实现strncpy
char *strncpy(char *destination, const char *source, size_t num) {
    int i = 0;
    //拷贝源字符串中num个字符到目标字符串
    while (source[i] != '\0' && i < num) {
        destination[i] = source[i];
        i++;
    }
    //将目标字符串中剩余的字符设置为'\0'
    while (i < num) {
        destination[i] = '\0';
        i++;
    }
    return destination;
}

//实现strcat
char *strcat(char *destination, const char *source) {
    int i = 0;
    int j = 0;
    //找到字符串的末尾
    while (destination[i] != '\0') {
        i++;
    }
    //拷贝字符串
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';
    return destination;
}

//实现strncat
char *strncat(char *destination, const char *source, size_t num) {
    int i = 0;
    //定位到最后一个字符
    while (destination[i] != '\0') {
        i++;
    }
    int j = 0;
    //拷贝num个字符
    while (source[j] != '\0' && j < num) {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';
    return destination;
}

//实现memcmp
int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    char *p1 = (char *) ptr1;
    char *p2 = (char *) ptr2;
    //遍历num个字符
    for (int i = 0; i < num; i++) {
        //ptr1和ptr2中的字符不相等，返回不同的字符
        if (p1[i] > p2[i]) {
            return 1;
        } else if (p1[i] < p2[i]) {
            return -1;
        }
    }
    return 0;
}

//strcmp
int strcmp(const char *str1, const char *str2) {
    int i = 0;
    //遍历str1和str2中的字符,比较大小
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;   //遇到首个不同的字符，str1>str2
        } else if (str1[i] < str2[i]) {
            return -1;  //遇到首个不同的字符，str2>str1
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;   //str1和str2中的字符相等，返回0
    } else if (str1[i] == '\0') {
        return -1;  //str1比str2短
    } else {
        return 1;   //str1比str2长
    }
}

//TODO 实现strcoll ??
//int strcoll(const char *str1, const char *str2) {
//    if (LC_COLLATE == "C" || LC_COLLATE == "POSIX") {
//        return strcmp(str1, str2);
//    } // 网站没有指明LC_COLLATE为其他值的具体处理方法？？？
//}

//实现strncmp
int strncmp(const char *str1, const char *str2, size_t num) {
    int i = 0;
    //遍历num个字符
    while (str1[i] != '\0' && str2[i] != '\0' && i < num) {
        if (str1[i] > str2[i]) {
            return 1;   //遇到首个不同的字符，str1>str2
        } else if (str1[i] < str2[i]) {
            return -1;  //遇到首个不同的字符，str2>str1
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;   //str1和str2中的字符相等，返回0
    } else if (str1[i] == '\0') {
        return -1;  //str1比str2短,the first character that does not match has a lower value in ptr1 than in ptr2
    } else {
        return 1;   //str1比str2长
    }
}

//TODO 实现strxfrm ??
//size_t strxfrm(char *destination, const char *source, size_t num) {
//    if (LC_COLLATE == 'C' || LC_COLLATE == 'POSIX') {
//        return reinterpret_cast<size_t>(strncpy(destination, source, num));
//        //如果 区域选项 是 "POSIX" 或者 "C", 那么 strxfrm() 同用 strncpy() 来 拷贝字符串是等价的.
//    }
//}


//实现memchr
void *memchr(const void *ptr, int value, size_t num) {
    char *p = (char *) ptr;
    //遍历num个字符
    for (int i = 0; i < num; i++) {
        //str中的字符与value相等，返回该字符的地址
        if (p[i] == value) {
            return p + i;
        }
    }
    return NULL;
}

//实现strchr
char *strchr(const char *str, int value) {
    int i = 0;
    //遍历str中的字符
    while (str[i] != '\0') {
        //str中的字符与value相等，返回该字符的地址
        if (str[i] == value) {
            return (char *) str + i;
        }
        i++;
    }
    return NULL;
}

//实现strcspn
size_t strcspn(const char *str1, const char *str2) {
    int i = 0;
    //遍历str1中的字符
    while (str1[i] != '\0') {
        //str2中的字符与str1中的字符相等，返回该字符的地址
        if (strchr(str2, str1[i]) != NULL) {
            return i;
        }
        i++;
    }
    return i;
}

//实现strpbrk
char *strpbrk(char *str1, const char *str2) {
    int i = 0;
    //遍历str1中的字符
    while (str1[i] != '\0') {
        //str2中的字符与str1中的字符相等，返回该字符的地址
        if (strchr(str2, str1[i]) != NULL) {
            return (char *) str1 + i;
        }
        i++;
    }
    return NULL;
}

//实现strrchr
char *strrchr(const char *str, int value) {
    int i = 0;
    //遍历str中的字符
    while (str[i] != '\0') {
        //str中的字符与value相等，返回该字符的地址
        if (str[i] == value) {
            return (char *) str + i;
        }
        i++;
    }
    return NULL;
}

//实现strspn
size_t strspn(const char *str1, const char *str2) {
    //检索字符串 str1 中第一个不在字符串 str2 中出现的字符下标。
    int i = 0;
    //遍历str1中的字符
    while (str1[i] != '\0' && strchr(str2, str1[i]) != NULL) {
        i++;
    }
    return i;
}

//实现strstr TODO 实现strstr
char *strstr(const char *str1, const char *str2) {
    int i = 0;
    //遍历str1中的字符
    while (str1[i] != '\0') {
        //str2中的字符与str1中的字符相等，返回该字符的地址
        if (strncmp(str1 + i, str2, strlen(str2)) == 0) {
            return (char *) str1 + i;
        }
        i++;
    }
    return NULL;
}


//实现strtok TODO 实现strtok
char *strtok(char *str, const char *delim) {
    static char *p = NULL;
    if (str != NULL) {
        p = str;
    }
    if (p == NULL) {
        return NULL;
    }
    //检索字符串 str 中第一个不在字符串 delim 中出现的字符下标。
    int i = strspn(p, delim);
    if (p[i] == '\0') {
        return NULL;
    }
    char *token = p + i;
    p = strpbrk(token, delim);
    if (p == NULL) {
        p = NULL;
    } else {
        *p = '\0';
        p++;
    }
    return token;
}

//实现memset TODO 实现memset
void *memset(void *ptr, int value, size_t num) {
    char *p = (char *) ptr;
    //遍历num个字符
    for (int i = 0; i < num; i++) {
        //str中的字符与value相等，返回该字符的地址
        p[i] = value;
    }
    return ptr;
}

//实现strerror TODO 实现strerror
char *strerror(int errnum) {
    return "strerror";
}


//实现stoi
int stoi(const char *str, size_t *idx, int base) {
}

//实现stol
long stol(const char *str, size_t *idx, int base) {
    //转换str为long型
    long result = 0;
    int i = 0;
    //遍历str中的字符
    if (str != NULL && str[0] != '\0') {


    }
}

//实现strlen
size_t strlen(const char *s) {
    int i = 0;
    //遍历字符串，直到遇到结束符
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

//实现strtol
long strtol(const char *str, char **endptr, int base) {
    //转换str为long型
    long int result = 0;
    int i = 0;
    bool isNegative = false;
    const char *pos = str;
    const char *start = pos;
    while (isspace(*pos)) {
        pos++;
    }
    //判断正负
    if (pos != NULL && *pos != '\0') {
        if (*pos == '+') {
            pos++;
        }
        if (*pos == '-') {
            pos++;
            isNegative = true;
        }
    }
    //如base已知，则可以准备转换
    if (base == 16 || base == 8) {
        if (base == 8 && *pos == '0') {
            pos++;
        }
        if (base == 16 && *pos == '0' && (*(pos + 1) == 'x' || *(pos + 1) == 'X')) {
            pos += 2;
        }
    }
    //base不明确，判断base
    if (base == 0) {
        base = 10;
        if (*pos == '0') {
            base = 8;
            pos++;
            if (*pos == 'x' || *pos == 'X') {
                pos++;
                base = 16;
            }
            if (*pos == 'b' || *pos == 'B') {
                pos++;
                base = 2;
            }
        }
    }
    //base数值错误
    if ((base < 2 || base > 36) || (base > 10 && base < 16)) {
        return 0;
    }

    while (*pos != '\0') {
        long long num = -1;
        //转换‘0’~'9'之间的字符
        if ((int) *pos >= 48 && (int) *pos <= 57) {
            num = (int) *pos - 48;
        }
        //转换‘a'~'f'之间的字符
        if (isalpha(*pos)) {
            num = (int) toupper(*pos) - 55;
        }
        //处理转换后数字
        if (num < base && num != -1) {
            if (isNegative == true) {
                if (result >= ((LONG_MIN + num) / base) {
                    result = result * base - num;
                } else {
                    result = LONG_MIN;
                }
            } else {
                if (result <= ((LONG_MAX - num) / base)) {
                    result = result * base + num;
                } else {
                    result = LONG_MAX;
                }
            }
        } else if (base == 16 && num > base && (*(pos - 1) == 'x' || *(pos - 1) == 'X')) {
            --pos;
            break;
        } else {
            break;
        }
        i++;
    }
    if (!isdigit(*(pos - 1)) && !isalpha(*(pos - 1)))
        pos = start;

    if (endptr)
        *endptr = (char *) pos;
    return result;
}

