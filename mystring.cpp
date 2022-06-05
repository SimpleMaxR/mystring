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
    //先确定长度
    int length = strlen(source.m_data);
    m_data = new char[length + 1];
    //循环赋值
    for (int i = 0; i < length; i++) {
        m_data[i] = source.m_data[i];
    }
    //没有终止符则加上终止符
    if (m_data[length - 1] != '\0') m_data[length - 1] = '\0';
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

//重载【】运算符
char Mystring::operator[](size_t index) const {
    if (index < 0)
        throw std::runtime_error("index is < 0");
    if (index > 0)
        throw std::runtime_error("index is > 0");
    return m_data[index];
}

char &Mystring::operator[](size_t index) {
    if (index >= strlen(m_data)) throw 1;
    return m_data[index];
}

//实现memcpy
void *Mystring::memcpy(const Mystring source, size_t num) {
    char *d = this->m_data;
    char *s = source.m_data;
    for (int i = 0; i < num; i++) {
        d[i] = s[i];
    }
    return this;
}

//实现memmove
void *Mystring::memmove(void *dest, const void *source, size_t count) {
    //确定目标和源的指针
    char *d = (char *) dest;
    char *s = (char *) source;
    //针对可能的内存覆盖情况进行改进
    if (d < s && (s + count > d)) {
        s = s + count - 1;
        d = d + count - 1;
        while (count--) {
            *d-- = *s--;
        }
    } else {
        while (count--) {
            *d-- = *s--;
        }
    }
    //返回复制后对象
    return d;
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

//实现strncpy
char *Mystring::strncpy(char *destination, const char *source, size_t num) {
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
char *Mystring::strcat(const char *source) {
    char *dest = this->m_data;
    int i = 0;
    int j = 0;
    //找到字符串的末尾
    while (dest[i] != '\0') {
        i++;
    }
    //拷贝字符串
    while (source[j] != '\0') {
        dest[i] = source[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

//实现strncat
char *Mystring::strncat(char *destination, const char *source, size_t num) {
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
int Mystring::memcmp(const void *ptr1, const void *ptr2, size_t num) {
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

//实现strcmp
int Mystring::strcmp(const char *str1, const char *str2) {
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
int Mystring::strcoll(const char *str1, const char *str2) {
//    if (LC_COLLATE == "C" || LC_COLLATE == "POSIX") {
//        return strcmp(str1, str2);
//    } // 网站没有指明LC_COLLATE为其他值的具体处理方法？？？
    return 0;
}

//实现strncmp
int Mystring::strncmp(const char *str1, const char *str2, size_t num) {
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
size_t Mystring::strxfrm(char *destination, const char *source, size_t num) {
//    if (LC_COLLATE == 'C' || LC_COLLATE == 'POSIX') {
//        return reinterpret_cast<size_t>(strncpy(destination, source, num));
//        //如果 区域选项 是 "POSIX" 或者 "C", 那么 strxfrm() 同用 strncpy() 来 拷贝字符串是等价的.
//    }
    return 0;
}


//实现memchr
void *Mystring::memchr(const void *ptr, int value, size_t num) {
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
char *Mystring::strchr(const char *str, int value) {
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
size_t Mystring::strcspn(const char *str1, const char *str2) {
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
char *Mystring::strpbrk(char *str1, const char *str2) {
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
char *Mystring::strrchr(const char *str, int value) {
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
size_t Mystring::strspn(const char *str1, const char *str2) {
    //检索字符串 str1 中第一个不在字符串 str2 中出现的字符下标。
    int i = 0;
    //遍历str1中的字符
    while (str1[i] != '\0' && strchr(str2, str1[i]) != NULL) {
        i++;
    }
    return i;
}

//实现strstr TODO 实现strstr
char *Mystring::strstr(const char *str1, const char *str2) {
//    int i = 0;
//    //遍历str1中的字符
//    while (str1[i] != '\0') {
//        //str2中的字符与str1中的字符相等，返回该字符的地址
//        if (strncmp(str1 + i, str2, strlen(str2)) == 0) {
//            return (char *) str1 + i;
//        }
//        i++;
//    }
//    return NULL;
    return NULL;
}


//实现strtok TODO 实现strtok
char *Mystring::strtok(char *str, const char *delim) {
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
void *Mystring::memset(void *ptr, int value, size_t num) {
    char *p = (char *) ptr;
    //遍历num个字符
    for (int i = 0; i < num; i++) {
        //str中的字符与value相等，返回该字符的地址
        p[i] = value;
    }
    return ptr;
}

//实现strerror TODO 实现strerror
char *Mystring::strerror(int errnum) {
    return "Error";
}


//实现stoi(利用strtol)
int Mystring::stoi(const char *str, size_t *idx, int base) {
    char *endptr;

    int result = strtol(str, &endptr, base);   //调用strtol进行转换
    if (endptr == str) {
        //转换失败或者没有转换，返回0
        return 0;
    }
    if (idx != NULL) {
        //idx不为空，记录转换后的字符串的下标
        *idx = endptr - str;
    }
    return result;
}

//实现stol(利用strtol)
long Mystring::stol(const char *str, size_t *idx, int base) {
    char *endptr;
    long result;
    //校验转换结果为long型可表示范围
    long long temp = strtol(str, &endptr, base);    //调用strtol进行转换,用更大的long long型变量存储转换结果，节省一次转换
    if (temp > LONG_MAX) {
        return LONG_MAX;   //转换结果超过long型可表示范围，返回long型最大值
    } else
        result = temp;   //转换结果在long型可表示范围内，直接返回转换结果

    if (endptr == str) {
        //转换失败或者没有转换，返回0
        return 0;
    }
    if (idx != NULL) {
        //idx不为空，记录转换后的字符串的下标
        *idx = endptr - str;
    }
    return result;
}

//实现strtol
long Mystring::strtol(const char *str, char **endptr, int base) {
    long int result = 0;        //存储转换结果
    bool isNegative = false;    //是否是负数
    const char *pos = str;      //指向str中的当前字符
    const char *start = pos;    //开始转换的位置

    //检查base数值
    if ((base < 2 || base > 36) && base != 0) {
        return -1;
    }

    //跳过空白字符
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

    //如base已知，则准备转换
    if (base == 16 || base == 8) {
        if (base == 16 && *pos == '0' && (*(pos + 1) == 'x' || *(pos + 1) == 'X')) {
            pos += 2;
        }
        if (base == 8 && *pos == '0') {
            pos++;
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
            if (isNegative) {
                if (result >= ((LONG_MIN + num) / base)) {
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
        pos++;
    }
    if (!isdigit(*(pos - 1)) && !isalpha(*(pos - 1)))
        pos = start;

    if (endptr)
        *endptr = (char *) pos;
    return result;
}

//实现strtoul
unsigned long int Mystring::strtoul(const char *str, char **endptr, int base) {
    return 0;
}


Mystring Mystring::operator=(const Mystring &str) {
    //如果自身与参数str指向同一个字符串，则直接返回自身
    if (&str == this) {
        return *this;
    }
        //如果自身与参数str指向不同的字符串，则释放自身所指向的字符串，并为自身重新赋值
    else {
        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }
}

//重载！=运算符

//int operator!=(const Mystring *str1, const Mystring *str2) {
//    return strcmp(str1, str2) != 0;
//}

//实现strlen
size_t Mystring::strlen() const {
    char *p = this->m_data;
    while (*p != '\0') {
        ++p;
    }
    return (p - this->m_data);
}

size_t Mystring::strlen(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}


Mystring::~Mystring() {
    delete[] m_data;
}

//运算符重载
Mystring &operator+(const Mystring &left, const Mystring &right) {
    Mystring result;
    result += left;
    result += right;
    return result;
}

Mystring &Mystring::operator+=(const Mystring &s) {
    unsigned length = this->strlen() + s.strlen();
    char *str = new char[length];

    for (unsigned j = 0; j < length; j++) {
        str[j] = m_data[j];
    }
    for (unsigned i = 0; i < s.strlen(); i++) {
        str[i + this->strlen()] = s.m_data[i];
    }
    return *this;
}





