//
// Created by Hugo-PC on 24/5/2022.
//
#include <iostream>
#include <climits>
#include "mystring.h"

size_t strlen(const char *s);

using namespace std;

//默认构造函数 default constructor
Mystring::Mystring() {
    m_capacity = 15; //默认容量
    m_length = 0;   //默认长度
    m_data = new char[m_length + 1]; //动态分配空间
    m_data[m_length] = '\0'; //结束符
}

//拷贝构造函数 copy constructor
Mystring::Mystring(const Mystring &source) {
    setNewLength(source.m_length);//设置新长度，容量将在函数中维护
    m_data = new char[m_length + 1];
    strcpy(m_data, source.m_data);  //拷贝源字符串
}

//实现 substring constructor
Mystring::Mystring(const Mystring &str, size_t pos, size_t len) {
    setNewLength(str.length() - pos);//设置新长度，容量将在函数中维护
    m_data = new char[m_capacity + 1];
    strncpy(m_data, str.m_data + pos, str.length());  //从str拷贝str.length()个字符到m_data
    m_data[len] = '\0';
}
//    if (pos > str.length()) {
//        pos = str.length();
//    }
//    if (len > str.length() - pos) {
//        len = str.length() - pos;
//    }
//    if (len <= 0) {
//        len = 0;
//    }
//    this->m_data = new char[len + 1];
//    strncpy(this->m_data, str.str + pos, len);
//    this->m_data[len] = '\0';
//    this->m_length = len;
//}

// from c-string
Mystring::Mystring(const char *s) {
    m_length = 0;
    m_capacity = 15;
    //判断是否为空
    if (s == nullptr) {
        //创建空字符串
        m_capacity = 15;
        this->m_length = 0;
        m_data = new char[m_length + 1];
        *m_data = '\0';
    } else {
        m_length = strlen(s); //设置容量为源字符串长度

        if (m_length > INT_MAX) {
            m_capacity = INT_MAX; //如果长度超过INT_MAX，则容量设置为INT_MAX
        } else {
            setNewCapacity(m_length); //否则根据长度设置容量
        }

        m_data = new char[m_length + 1];  //分配空间
        strcpy(m_data, s);  //拷贝源字符串
    }
}

//from sequence constructor
Mystring::Mystring(const char *s, size_t n) {
    //判断是否为空
    if (s == nullptr) {
        //创建空字符串
        Mystring();
    } else {
        m_length = n; //设置容量为源字符串长度
        if (m_length > INT_MAX) {
            m_capacity = INT_MAX; //如果长度超过INT_MAX，则容量设置为INT_MAX
        } else {
            m_capacity = m_length; //否则容量设置为长度
        }
        m_data = new char[m_capacity + 1];  //分配空间
        strncpy(m_data, s, n);  //拷贝源字符串
        m_data[n] = '\0';

    }

}

//fill constructor
Mystring::Mystring(size_t n, char c) {
    //判断是否为空
    if (n == 0) {
        //创建空字符串
        Mystring();
    } else {
        m_length = n; //设置容量为源字符串长度
        if (m_length > INT_MAX) {
            m_capacity = INT_MAX; //如果长度超过INT_MAX，则容量设置为INT_MAX
        } else {
            m_capacity = m_length; //否则容量设置为长度
        }
        m_data = new char[m_capacity + 1];  //分配空间
        for (size_t i = 0; i < n; i++) {
            m_data[i] = c;  //拷贝源字符
        }
    }
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
void *Mystring::memcpy(void *dest, const void *src, size_t num) {
    // 当目标或源为空时，返回错误
    if (dest == nullptr || src == nullptr) {
        throw std::runtime_error("dest or src is nullptr");
    }
    //当目标和源一致，直接返回
    if (dest == src) {
        return dest;
    }
    char *d = (char *) dest;
    const char *s = (const char *) src;
    for (size_t i = 0; i < num; i++) {
        d[i] = s[i];
    }
    return dest;
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
    return (char *) memcpy(cpy, src, strlen(src) + 1);
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
    while (i < strlen(destination)) {
        destination[i] = '\0';
        i++;
    }
    return destination;
}

//实现strcat
char *Mystring::strcat(char *d, const char *s) {
    //make sure destination and source is not overlap
    if ((d < s && (d + strlen(d) > s)) || (s < d && s + strlen(s) > d)) {
        throw std::runtime_error("destination and source is overlap");
    }
    if (d == s) {
        return d;
    }
    int i = 0;
    int j = 0;
    //定位字符串的末尾
    while (d[i] != '\0') {
        i++;
    }
    //拷贝源字符串中的字符到目标字符串
    //直到源字符串的末尾 或者 目标字符串最大长度
    size_t n = strlen(s);
    while (s[j] != '\0' && j < n) {
        d[i] = s[j];
        i++;
        j++;
    }
    d[i] = '\0';
    return d;
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
//    把存储区 str1 和存储区 str2 的前 n 个字节进行比较
//    如果返回值 < 0，则表示 str1 小于 str2。
//    如果返回值 > 0，则表示 str1 大于 str2。
//    如果返回值 = 0，则表示 str1 等于 str2。
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
    /*把 str1 和 str2 进行比较，最多比较前 n 个字节
    如果返回值 < 0，则表示 str1 小于 str2。
    如果返回值 > 0，则表示 str1 大于 str2。
    如果返回值 = 0，则表示 str1 等于 str2。*/
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

//实现strxfrm
size_t Mystring::strxfrm(char *destination, const char *source, size_t num) {
//    根据程序当前的区域选项中的 LC_COLLATE 来转换字符串 src 的前 n 个字符，并把它们放置在字符串 dest 中
    //简单实现，直接拷贝source到destination
    int i = 0;
    while (source[i] != '\0' && i < num) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return i;
}


//实现memchr
void *Mystring::memchr(const void *ptr, int value, size_t num) {
//    在参数 str 所指向的字符串的前 n 个字节中搜索第一次出现字符 c（一个无符号字符）的位置。

    char *p = (char *) ptr;
    //遍历num个字符
    for (int i = 0; i < num; i++) {
        //str中的字符与value相等，返回该字符的地址
        if (p[i] == value) {
            return p + i;
        }
    }
    return nullptr;//没有找到value，返回NULL
}

//实现strchr
char *Mystring::strchr(const char *str, int value) {
//  在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置。

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
//  返回 str1 中首次出现 str2 中的字符的位置，如果没有出现，则返回 str1 的长度。

    int i = 0;
    //遍历str1中的字符
    while (str1[i] != '\0') {
        //检查当前选中的 str1 的字符是否在 str2 中出现
        if (strchr(str2, str1[i]) != NULL) {
            return i; //出现则返回当前位置
        }
        i++;
    }
    return i;
}

//实现strpbrk
char *Mystring::strpbrk(char *str1, const char *str2) {
//  检索字符串 str1 中第一个匹配字符串 str2 中字符的字符，不包含空结束字符

    int i = 0;
    //遍历str1中的字符
    while (str1[i] != '\0') {
        //str2中的字符与str1中的字符相等，返回该字符的地址
        if (strchr(str2, str1[i]) != NULL) {
            return (str1 + i);
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
    //检索字符串 str1 中第一个不在字符串 str2 中出现的字符的下标。
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


//实现strtok TODO实现strtok
char *Mystring::strtok(char *str, const char *delim) {
//    分解字符串 str 为一组字符串，delim 为分隔符。
    static char *p = NULL;
    if (str != NULL) {
        p = str;
    }
    if (p == NULL) {
        return NULL;
    }

    int i = strspn(p, delim);   //检索字符串 str 中第一个不在字符串 delim 中出现的字符下标。
    if (p[i] == '\0') {
        return NULL;
    }
    char *token = p + i;
    p = strpbrk(token, delim); //检索字符串 str 中第一个在字符串 delim 中出现的字符下标。
    if (p == NULL) {
        p = NULL;
    } else {
        *p = '\0';
        p++;
    }
    return token;
}

//char* Mystring::strtok(char* str, const char* delimiters) {
//    static char *pstr = nullptr;
//
//    if (str == nullptr && pstr == nullptr)
//        return nullptr;
//        //strtok函数第一个参数不为nullptr，函数将找到str中第一个标记，
//        //strtok函数将保存它在字符串中的位置。
//    else if (str != nullptr) {
//        int counter1 = 0;
//        for (int i = 0; *(str + counter1) != *(delimiters + i); i++) {
//            if (*(delimiters + i) == '\0') {
//                counter1++;
//                i = -1;
//            }
//            if (*(str + counter1) == '\0')
//                return nullptr;
//        }
//        *(str + counter1) = '\0';
//        pstr = str + counter1;
//        return pstr;
//    }
//
//        //strtok函数第一个参数为nullptr，函数在同一个字符串中被保存的位置开始，直接找下一个标记
//    else if (str == nullptr && pstr != nullptr) {
//        int counter2 = 1;
//        for (int i = 0; *(pstr + counter2) != *(delimiters + i); i++) {
//            if (*(delimiters + i) == '\0') {
//                counter2++;
//                i = -1;
//            }
//            if (*(pstr + counter2) == '\0')
//                return nullptr;
//        }
//        *(pstr + counter2) = '\0';
//        pstr = pstr + counter2;
//        return pstr;
//    }
//}

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

//实现strerror
char *Mystring::strerror(int errnum) {
    char *errmsg;
    switch (errnum) {
        case 0:
            strcpy(errmsg, "Success");
            break;
        case 1:
            strcpy(errmsg, "EPERM");
            break;
        case 2:
            strcpy(errmsg, "ENOENT");
            break;
        case 3:
            strcpy(errmsg, "ESRCH");
            break;
        case 4:
            strcpy(errmsg, "EINTR");
            break;
        case 5:
            strcpy(errmsg, "EIO");
            break;
        case 6:
            strcpy(errmsg, "ENXIO");
            break;
        case 7:
            strcpy(errmsg, "E2BIG");
            break;
        case 8:
            strcpy(errmsg, "ENOEXEC");
            break;
        default:
            strcpy(errmsg, "Unknown error");
            break;
    }
    return errmsg;
}

//实现stoi(利用strtol)
int Mystring::stoi(const char *str, size_t *idx, int base) {
    char *endptr;
    int result;
    long temp = strtol(str, &endptr, base);
    result = (temp > INT_MAX ? INT_MAX : temp); //检查是否超出范围,超出范围则返回INT_MAX
    if (endptr == str) {
        //转换失败或者没有转换，返回0
        return -1;
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

//TODO 实现stoul(利用strtoul)
unsigned long Mystring::stoul(const Mystring &str, size_t *idx, int base) {
    return 0;
}

//TODO 实现stoll(利用strtoll)
long long Mystring::stoll(const Mystring &str, size_t *idx, int base) {
    return 0;
}

//TODO 四个实现
unsigned long long Mystring::stoull(const Mystring &str, size_t *idx, int base) {
    return 0;
}

float Mystring::stof(const Mystring &str, size_t *idx) {
    return 0;
}

double Mystring::stod(const Mystring &str, size_t *idx) {
    return 0;
}

long double Mystring::stold(const Mystring &str, size_t *idx) {
    return 0;
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
//unsigned long int Mystring::strtoul(const char *str, char **endptr, int base) {
//#define ULONG_MAX ((unsigned long) -1)
//    const char *s = str;
//    unsigned long acc;
//    int c;
//    unsigned long maxValueWithoutLastDigit;
//    int neg = 0, any, lastDigit;
//
////跳过空白，c定位到第一个非空白字符，s指向c的下一个字符
//    do {
//        c = *s++;
//    } while (isspace(c));
//
//
////    定义正负
//    if (c == '-') {
//        neg = 1;
//        c = *s++;
//    } else if (c == '+')
//        c = *s++;
//
//    //利用0x前缀判断是16进制
//    if ((base == 0 || base == 16) &&
//        c == '0' && (*s == 'x' || *s == 'X')) {
//        c = s[1]; //跳过0x
//        s += 2; //跳到c的下一个字符
//        base = 16;
//    }
//
////    利用0前缀判断是8进制
//    if (base == 0)
//        base = c == '0' ? 8 : 10;
//
//    maxValueWithoutLastDigit = neg ? -(unsigned long) LONG_MIN : LONG_MAX; //最大值的前n-1位数
//    lastDigit = maxValueWithoutLastDigit % (unsigned long) base; //最大值的最后一位数
//    maxValueWithoutLastDigit /= (unsigned long) base;
//    //透过这两个变量，我们可以知道，如果输入的数字超过了最大值，那么它的前x位将吻合”最大值的前n-1位“，而且它的最后一位数就会大于“最大值的最后一位数”。
//
//    for (acc = 0, any = 0;; c = *s++) {
//        if (isdigit(c))
//            c -= '0'; // 如果是数字，则减去'0' ？？？？？
//        else if (isalpha(c))
//            if (isupper(c)) {
//                c -= 'A' - 10;
//            } else {
//                c -= 'a' - 10;
//            } // 如果是字母，则减去字母的值
//        else
//            break; // 如果不是数字或字母，则跳出循环
//
//        if (c >= base)
//            break;
//
//        if (any < 0 || acc > maxValueWithoutLastDigit || (acc == maxValueWithoutLastDigit && c > lastDigit))
//            any = -1; //标记为溢出
//        else {
//            any = 1;    //标记为有效
//            acc *= base;    //转换为base进制
//            acc += c;    //加上当前的数字
//        }
//    }
//
//    if (any < 0) {
//        acc = neg ? LONG_MIN : LONG_MAX;
//        throw "overflow";
//    } else if (neg)
//        acc = -acc; //如果是负数，则取反
//    if (endptr != 0)
//        *endptr = (char *) (any ? s - 1 : str); //如果有效，则指向最后一个有效字符，否则指向起始位置
//
//    return (acc); //返回转换后的数字, 大功告成！！！！！！
//}

//实现 =运算符重载
Mystring &Mystring::operator=(const Mystring &str) {
    // override operator =
    // 如果自赋值，则直接返回，否则释放原有内存，再申请新内存，拷贝字符串
    if (this != &str) {
        delete[] this->m_data;
        this->m_data = new char[strlen(str.m_data) + 1];
        this->m_length = str.m_length;
        this->m_capacity = str.m_capacity;
        strcpy(this->m_data, str.m_data);
    }
    return *this;
}

Mystring &Mystring::operator=(const char *str) {
    // override operator =
    if (this->m_data != str) {
        delete[] this->m_data;
        this->m_data = new char[strlen(str) + 1];
        strcpy(this->m_data, str);
    }
    return *this;
}

Mystring &Mystring::operator=(char c) {
    // override operator =
    if (this->m_data != &c) {
        delete[] this->m_data;//释放原有内存
        this->m_data = new char[2]; // 分配一个字符的内存
        this->m_length = 1; // 字符串长度为1
        this->m_capacity = 15;// 字符串容量为15
        this->m_data[0] = c;
        this->m_data[1] = '\0';
    }
    return *this;
}

//TODO 实现迭代器
//Iterator Mystring::begin() {
//    return Iterator(this, 0);
//}



//    //如果自身与参数str指向同一个字符串，则直接返回自身
//    if (&str == this) {
//        return *this;
//    }
//        //如果自身与参数str指向不同的字符串，则释放自身所指向的字符串，并为自身重新赋值
//    else {
//        delete[] m_data;
//        m_data = new char[strlen(str.m_data) + 1];
//        strcpy(m_data, str.m_data);
//        return *this;
//    }

//实现size()函数
size_t Mystring::size() const {
    return m_length; //返回字符串长度
}

//实现length()函数
size_t Mystring::length() const {
    return m_length; //返回字符串长度
}

//实现max_size
size_t Mystring::max_size() const {
    size_t t = -1;
    return t;//返回字符串最大容量 （size_t 类型的最大值）
}

//实现resize (使用’\0’作为默认参数，省去一次重载）
void Mystring::resize(size_t n, char c = '\0') {
    //如果n小于字符串长度，则截断字符串
    if (n < m_length) {
        m_data[n] = '\0';
        m_length = n;
    }
        //如果n大于字符串长度，则扩展字符串
    else if (n > m_length) {
        //如果字符串容量不足，则扩展字符串容量
        if (n > m_capacity) {
            char *temp = new char[n + 1];
            strcpy(temp, m_data);
            delete[] m_data;
            m_data = temp;
            m_capacity = n;
        }
        //如果字符串容量足够，则在字符串末尾添加字符c
        for (size_t i = m_length; i < n; i++) {
            m_data[i] = c;
        }
        m_data[n] = '\0';
        m_length = n;
    }
}

//实现capacity()函数
size_t Mystring::capacity() const {
    return this->m_capacity;
}

//实现reserve
void Mystring::reserve(Mystring s, size_t n) {
//    Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
//    If n is 0, this function has no effect.
//    If n is greater than the current capacity, the function increases the capacity to n.
//    If n is less than the current capacity, the function does nothing.
    if (n > m_capacity) {
        char *temp = new char[n + 1];
        setNewCapacity(n, temp);
        strcpy(temp, m_data);
        delete[] m_data;
        m_data = temp;
        m_capacity = n;
    }

}

//实现clear
void Mystring::clear() {
    //清空字符串
    delete[] this->m_data;
}

//实现empty
bool Mystring::empty() const {
    //如果字符串长度为0，则返回true
    if (this->m_length == 0) {
        return true;
    }
}

//实现shrink_to_fit
void Mystring::shrink_to_fit() {
    //请求精简字符串容量
    size_t n = strlen(m_data);
    n = this->m_capacity - this->strlen(m_data);
    if (n > 15) {
        while (n > 15) {
            n = n / 2;
        }
        setNewCapacity(n / 15);
    }
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

//实现at
char &Mystring::at(size_t pos) {
    if (pos >= strlen(m_data) || pos < 0) throw "Out of range";
    return m_data[pos];
}

const char &Mystring::at(size_t pos) const {
    if (pos >= strlen(m_data) || pos < 0) throw "Out of range";
    return m_data[pos];
}

char &Mystring::back() {
    if (m_length == 0) throw "Out of range";
    return m_data[m_length - 1];
}

const char &Mystring::back() const {
    if (m_length == 0) throw "Out of range";
    return m_data[m_length - 1];
}

char &Mystring::front() {
    return m_data[0];
}

const char &Mystring::front() const {
    return m_data[0];
}

//+=运算符重载
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

Mystring &Mystring::operator+=(const char *&s) {
    unsigned length = this->strlen() + strlen(s);
    char *str = new char[length];

    for (unsigned j = 0; j < length; j++) {
        str[j] = m_data[j];
    }
    for (unsigned i = 0; i < strlen(s); i++) {
        str[i + this->strlen()] = s[i];
    }
    return *this;
}

Mystring &Mystring::operator+=(char c) {
    unsigned length = this->strlen() + 1;
    char *str = new char[length];

    for (unsigned j = 0; j < length; j++) {
        str[j] = m_data[j];
    }
    str[length - 1] = c;
    return *this;
}

Mystring &Mystring::append(Mystring &first, const Mystring &last) {
//    在string末尾添加str
    unsigned oldLength = first.strlen(); //保存原来的长度，用于比较
    setNewLength(oldLength + last.m_length + 1); //设置新的长度为旧长度加str长度(容量由setNewLength维护)

    if (strlen(last.m_data)) { //last长度不为0，则拷贝str的内容
        strncpy(first.m_data + oldLength, last.m_data, strlen(last.m_data)); //拷贝last的内容到first的末尾
    } else {
        return first; //last长度为0，则直接返回first
    }
    return first;
}

Mystring &Mystring::append(Mystring &first, const Mystring &str, size_t subpos, size_t sublen) {
    //add str to first, starting at position subpos, for sublen characters
    if (subpos < 0 || subpos > str.strlen()) {
        throw "subpos is out of range";
    }
    if (sublen < 0 || sublen > str.strlen() || sublen == npos) {
        sublen = str.strlen() - subpos;
    }

    unsigned oldLength = first.strlen(); //保存原来的长度
    char *pos = str.m_data + subpos;    //设置pos指向开始拷贝位置
    char *end = str.m_data + subpos + sublen;   //设置end指向结束拷贝位置
    setNewLength(oldLength + sublen); //设置新的长度为旧长度加要复制的长度(容量由setNewLength维护)
    while (pos < end) {
        first.m_data[oldLength++] = *pos++;
    }
    return first;
}


Mystring &Mystring::append(Mystring &first, const char *s) {
    //在string末尾添加s
    unsigned oldLength = first.strlen(); //保存原来的长度，用于比较
    size_t sLen = strlen(s) + 1; //设置sLen为s的长度(include '\0')
    setNewLength(first.strlen() + sLen); //设置新的长度为first长度加s长度(容量由setNewLength维护)
    while (sLen--) {
        first.m_data[oldLength++] = *s++;
    }
    return first;
}

Mystring &Mystring::append(Mystring &first, const char *s, size_t n) {
    unsigned oldLength = first.strlen(); //保存原来的长度，用于比较
    size_t cLen = n < strlen(s) ? n : strlen(s); //如果n比s短，则取n，否则取s的长度
    setNewLength(first.strlen() + cLen); //设置新的长度为first长度加s长度(容量由setNewLength维护)
    while (cLen--) {
        first.m_data[oldLength++] = *s++;
    }
    return first;
}

Mystring &Mystring::append(Mystring &first, size_t n, char c) {
    unsigned oldLength = first.strlen(); //保存原来的长度，用于比较
    setNewLength(oldLength + n); //设置新的长度为first长度加n(容量由setNewLength维护)
    while (n--) {
        first.m_data[oldLength++] = c;
    }
}

//TODO 迭代器
template<class InputIterator>
Mystring &Mystring::append(InputIterator first, InputIterator last) {
//    Appends a copy of the sequence of characters in the range [first,last), in the same order.
    unsigned oldLength = this->strlen(); //保存原来的长度，用于比较
    setNewLength(oldLength + std::distance(first, last)); //设置新的长度为first到last的距离(容量由setNewLength维护)
    while (first != last) {
        m_data[oldLength++] = *first++;
    }
    return *this;
}


void Mystring::push_back(char c) {
    //在string末尾添加c
    unsigned oldLength = this->strlen(); //保存原来的长度，用于比较
    setNewLength(oldLength + 1); //设置新的长度为旧长度加1(容量由setNewLength维护)
    m_data[oldLength] = c;
    m_data[oldLength + 1] = '\0';
    return;
}

void Mystring::push_back(Mystring &s, char c) {
    unsigned oldLength = s.strlen(); //保存原来的长度，用于比较
    s.setNewLength(oldLength + 1); //设置新的长度为旧长度加1(容量由setNewLength维护)
    s.m_data[oldLength] = c;
    s.m_data[oldLength + 1] = '\0';
}

Mystring &Mystring::assign(Mystring &first, const Mystring &str) {
    //assign str to first
    first.setNewLength(str.strlen()); //设置新的长度为str长度(容量由setNewLength维护)
    delete[] first.m_data; //释放原来的内存
    first.m_data = str.m_data;
}

Mystring &Mystring::assign(Mystring &first, const Mystring &str, size_t subpos, size_t sublen) {
//    assign str to first, starting at position subpos, for sublen characters
    if (subpos < 0 || subpos > str.strlen()) { //如果subpos越界
        throw "subpos is out of range";
    }
    if (sublen > str.strlen() || sublen == npos) {
        sublen = str.strlen() - subpos;
    }
    first.setNewLength(sublen); //设置新的长度为sublen(容量由setNewLength维护)
    delete[] first.m_data; //释放原来的空间
    for (int i = 0; i < sublen; i++) {
        first.m_data[i] = str.m_data[subpos + i];
    }
    first.m_data[sublen] = '\0';
    return first;
}

Mystring &Mystring::assign(Mystring &first, const char *s) {
    //assign s to first
    //make sure s is not null
    if (s == nullptr) {
        throw "s is nullptr";
    } else {
        first.setNewLength(
                strlen(s)); //set new length to first with s's length,(capacity is maintained by setNewLength)
        delete[] first.m_data; //release old memory
        for (int i = 0; i < strlen(s); i++) {
            first.m_data[i] = s[i]; //copy s to first
        }
        if (first.m_data[first.strlen()] != '\0') {
            first.m_data[first.strlen()] = '\0'; //if s is not null-terminated, add null-terminator
        }
    }
    return first;
}

Mystring &Mystring::assign(Mystring &first, const char *s, size_t n) {
    //assign s to first, for n characters
    //make sure s is not null
    if (s == nullptr || n >= strlen(s)) {
        throw "s is nullptr or n is too large";
    } else {
        first.setNewLength(n); //set new length to first with n,(capacity is maintained by setNewLength)
        delete[] first.m_data; //release old memory
        for (int i = 0; i < n; i++) {
            first.m_data[i] = s[i]; //copy s to first
        }
        if (first.m_data[first.strlen()] != '\0') {
            first.m_data[first.strlen()] = '\0'; //if s is not null-terminated, add null-terminator
        }
    }
    return first;
}

Mystring &Mystring::assign(Mystring &first, size_t n, char c) {
    //assign n copies of c to first
    first.setNewLength(n); //set new length to first with n,(capacity is maintained by setNewLength)
    delete[] first.m_data; //release old memory
    for (int i = 0; i < n; i++) {
        first.m_data[i] = c; //copy c to first
    }
    first.m_data[n] = '\0'; //add null-terminator
    return first;
}

template<class InputIterator>
Mystring &Mystring::assign(InputIterator first, InputIterator last) {
    //assign the sequence of characters in the range [first,last) to first
    //make sure first is not null
    if (first == nullptr) {
        throw "first is nullptr";
    } else {
        size_t n = std::distance(first, last); //get the distance between first and last
        first.setNewLength(n); //set new length to first with n,(capacity is maintained by setNewLength)
        delete[] first.m_data; //release old memory
        for (int i = 0; i < n; i++) {
            first.m_data[i] = *first++; //copy first to first
        }
        if (first.m_data[first.strlen()] != '\0') {
            first.m_data[first.strlen()] = '\0'; //if first is not null-terminated, add null-terminator
        }
    }
    return first;
}

Mystring &Mystring::insert(size_t pos, const Mystring &str, Mystring &first) {
    //insert str to first in position pos
    //make sure pos is not out of range
    if (pos > first.strlen()) {
        throw "pos is out of range";
    } else {
        size_t n = str.strlen(); //get the length of str
        first.setNewLength(
                first.strlen() + n); //set new length to first with n,(capacity is maintained by setNewLength)
        memmove(first.m_data + pos + n, first.m_data + pos,
                strlen(first.m_data) - pos + 1); //move the rest of first to the right
        memcpy(first.m_data + pos, str.c_str(), str.size());
    }
    return first;
}


Mystring &Mystring::insert(Mystring &first, size_t pos, const Mystring &str, size_t subpos, size_t sublen) {
    //insert str to first in position pos, starting at position subpos, for sublen characters
    //make sure pos is not out of range
    if (pos > first.strlen()) {
        throw "pos is out of range";
    } else {
        if (subpos < 0 || subpos > str.strlen()) { //如果subpos越界
            throw "subpos is out of range";
        }
        if (sublen > str.strlen() || sublen == npos) {
            sublen = str.strlen() - subpos;
        }
        size_t n = sublen; //get the length of str
        first.setNewLength(
                first.strlen() + n); //set new length to first with n,(capacity is maintained by setNewLength)
        memmove(first.m_data + pos + n, first.m_data + pos,
                strlen(first.m_data) - pos + 1); //move the rest of first to the right
        memcpy(first.m_data + pos, str.c_str() + subpos, sublen);
    }
    return first;
}

Mystring &Mystring::insert(Mystring &first, size_t pos, const char *s) {
    //insert s to first in position pos
    //make sure pos is not out of range
    if (pos > first.strlen()) {
        throw "pos is out of range";
    } else {
        size_t n = strlen(s); //get the length of s
        first.setNewLength(
                first.strlen() + n); //set new length to first with n,(capacity is maintained by setNewLength)
        memmove(first.m_data + pos + n, first.m_data + pos,
                strlen(first.m_data) - pos + 1); //move the rest of first to the right
        memcpy(first.m_data + pos, s, n);
    }
    return first;
}

Mystring &Mystring::insert(Mystring &first, size_t pos, const char *s, size_t n) {
    //insert s to first in position pos
    //make sure pos is not out of range
    if (pos > first.strlen()) {
        throw "pos is out of range";
    } else {
        first.setNewLength(
                first.strlen() + n); //set new length to first with n,(capacity is maintained by setNewLength)
        memmove(first.m_data + pos + n, first.m_data + pos,
                strlen(first.m_data) - pos + 1); //move the rest of first to the right
        for (int i = 0; i < n; i++) {
            first.m_data[pos + i] = s[i];
        }
    }
    return first;
}

Mystring &Mystring::insert(Mystring &first, size_t pos, size_t n, char c) {
    //insert n copies of c to first in position pos
    //make sure pos is not out of range
    if (pos > first.strlen()) {
        throw "pos is out of range";
    } else {
        first.setNewLength(
                first.strlen() + n); //set new length to first with n,(capacity is maintained by setNewLength)
        memmove(first.m_data + pos + n, first.m_data + pos,
                strlen(first.m_data) - pos + 1); //move the rest of first to the right
        for (int i = 0; i < n; i++) {
            first.m_data[pos + i] = c; //put n copies of c to first
        }
    }
}

//void Mystring::insert(iterator p, size_t n, char c) {
//    //insert n copies of c to first in position pos
//    //make sure pos is not out of range
//        setNewLength(strlen() + n); //set new length to first with n,(capacity is maintained by setNewLength)
//        memmove(m_data + p + n, m_data + p , strlen(m_data) - p + 1); //move the rest of first to the right
//        for (int i = 0; i < n; i++) {
//            m_data[p + i] = c; //put n copies of c to first
//        }
//}

//iterator Mystring::insert(iterator p, char c) {
//    //insert c to first in position pos
//    //make sure pos is not out of range
//    if (p == end()) {
//        push_back(c);
//    } else {
//        insert(p, 1, c);
//    }
//    return p;
//}

//template<class InputIterator>
//Mystring &Mystring::insert(iterator p, InputIterator first, InputIterator last) {
//    return <#initializer#>;
//}
//
Mystring &Mystring::erase(size_t pos, size_t len) {
    //erase len characters from first in position pos
    //make sure pos is not out of range
    if (pos > strlen()) {
        throw "pos is out of range";
    } else {
        if (len > strlen() - pos) {
            len = strlen() - pos;
        }
        memmove(m_data + pos, m_data + pos + len, strlen(m_data) - pos - len + 1);
        setNewLength(strlen() - len);
    }
    return *this;
}

//iterator Mystring::erase(iterator p) {
//    return iterator();
//}
//
//iterator Mystring::erase(iterator first, iterator last) {
//    return iterator();
//}
//
Mystring &Mystring::replace(size_t pos, size_t len, const Mystring &str) {
    //replace len characters from first in position pos with str
    //make sure pos is not out of range
    if (pos > strlen()) {
        throw "pos is out of range";
    } else {
        if (len > strlen() - pos) {
            len = strlen() - pos;
        }
        memcpy(m_data + pos, str.c_str(), str.strlen());
        setNewLength(strlen());
    }
}

//Mystring &Mystring::replace(iterator i1, iterator i2, const Mystring &str) {
//    return <#initializer#>;
//}
//
Mystring &Mystring::replace(size_t pos, size_t len, const Mystring *str, size_t subpos, size_t sublen) {
    //replace len characters from first in position pos with str
    //make sure pos is not out of range
    if (pos > strlen()) {
        throw "pos is out of range";
    } else {
        if (len > strlen() - pos) {
            len = strlen() - pos;
        }
        if (subpos > strlen()) {
            throw "subpos is out of range";
        }
        if (sublen > strlen() || sublen == npos) {
            sublen = strlen() - subpos;
        }
        memcpy(m_data + pos, str->c_str() + subpos, sublen);
        setNewLength(strlen());
    }
    return *this;
}

Mystring &Mystring::replace(size_t pos, size_t len, const char *s) {
    //replace len characters from first in position pos with s
    //make sure pos is not out of range
    if (pos > strlen()) {
        throw "pos is out of range";
    } else {
        if (len > strlen() - pos) {
            len = strlen() - pos;
        }
        memcpy(m_data + pos, s, strlen(s));
        setNewLength(strlen());
    }
    return *this;
}

//Mystring &Mystring::replace(iterator i1, iterator i2, const char *s) {
//    return <#initializer#>;
//}
//
Mystring &Mystring::replace(size_t pos, size_t len, const char *s, size_t n) {
    //replace len characters from first in position pos with s
    //make sure pos is not out of range
    if (pos > strlen()) {
        throw "pos is out of range";
    } else {
        if (len > strlen() - pos) {
            len = strlen() - pos;
        }
        memcpy(m_data + pos, s, n);
        setNewLength(strlen());
    }
    return *this;
}

//Mystring &Mystring::replace(iterator i1, iterator i2, const char *s, size_t n) {
//    return <#initializer#>;
//}
//
Mystring &Mystring::replace(size_t pos, size_t len, size_t n, char c) {
    //replace len characters from first in position pos with n copies of c
    //make sure pos is not out of range
    if (pos > strlen()) {
        throw "pos is out of range";
    } else {
        if (len > strlen() - pos) {
            len = strlen() - pos;
        }
        memset(m_data + pos, c, n);
        setNewLength(strlen());
    }
    return *this;
}

//Mystring &Mystring::replace(iterator i1, iterator i2, size_t n, char c) {
//    return <#initializer#>;
//}
//
//template<class InputIterator>
//Mystring &Mystring::replace(iterator i1, iterator i2, InputIterator first, InputIterator last) {
//    return <#initializer#>;
//}

void Mystring::swap(Mystring &str) {
    //swap the contents of str with *this
    char *temp = str.m_data;
    str.m_data = m_data;
    m_data = temp;
}

void Mystring::pop_back() {
    //remove the last character from first
    size_t len = strlen();
    if (len > 0) {
        setNewLength(len - 1);
    }
}

void Mystring::pop_back(Mystring &s) {
    //remove the last character from first
    size_t len = s.strlen();
    if (len > 0) {
        s.setNewLength(len - 1);
    }
}

const char *Mystring::c_str() const {
    //return a pointer to the null-terminated string
    return m_data;
}

const char *Mystring::data() const {
    //return a pointer to the null-terminated string
    return m_data;
}

allocator_type Mystring::get_allocator() const {
    //return the allocator object
    return allocator_type();
}

size_t Mystring::copy(Mystring &src, char *s, size_t len, size_t pos) {
    //copy len characters from src in position pos to s
    //make sure pos is not out of range
    if (pos > src.strlen()) {
        throw "pos is out of range";
    } else {
        if (len > src.strlen() - pos) {
            len = src.strlen() - pos;
        }
        memcpy(s, src.c_str() + pos, len);
    }
    return len;
}

//size_t Mystring::find(const Mystring &str, size_t pos) const {
//    //find
//}

//size_t Mystring::find(const char *s, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find(const char *s, size_t pos, size_t n) const {
//    return 0;
//}
//
//size_t Mystring::find(char c, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::rfind(const Mystring &str, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::rfind(const char *s, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::rfind(const char *s, size_t pos, size_t n) const {
//    return 0;
//}
//
//size_t Mystring::rfind(char c, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_first_of(const Mystring &str, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_first_of(const char *s, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_first_of(const char *s, size_t pos, size_t n) const {
//    return 0;
//}
//
//size_t Mystring::find_first_of(char c, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_last_of(const Mystring &str, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_last_of(const char *s, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_last_of(const char *s, size_t pos, size_t n) const {
//    return 0;
//}
//
//size_t Mystring::find_last_of(char c, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_first_not_of(const Mystring &str, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_first_not_of(const char *s, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_first_not_of(const char *s, size_t pos, size_t n) const {
//    return 0;
//}
//
//size_t Mystring::find_first_not_of(char c, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_last_not_of(const Mystring &str, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_last_not_of(const char *s, size_t pos) const {
//    return 0;
//}
//
//size_t Mystring::find_last_not_of(const char *s, size_t pos, size_t n) const {
//    return 0;
//}
//
//size_t Mystring::find_last_not_of(char c, size_t pos) const {
//    return 0;
//}
//
//Mystring Mystring::substr(size_t pos, size_t len) const {
//    return Mystring();
//}
//
//int Mystring::compare(const Mystring &str) const {
//    return 0;
//}








//运算符重载

Mystring &operator+(const Mystring &left, const Mystring &right) {
    //concatenate two strings


}












//其他


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

size_t Mystring::strlen(const char *str) const {
    int i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}




void Mystring::setNewCapacity(size_t newCapacity) {
    m_capacity = 15; //init capacity value is 15
    while (newCapacity > m_capacity) {
        m_capacity *= 2; //capacity should be a multiple of 15
    }
}

void Mystring::setNewCapacity(size_t n, Mystring s) {
    s.m_capacity = 15; //init capacity value is 15
    while (n > s.m_capacity) {
        s.m_capacity *= 2; //capacity should be a multiple of 15
    }
}

void Mystring::setNewLength(size_t newLength) {
    // if newLength is longer than capacity for now, make a new capacity
    if (newLength > m_capacity) {
        setNewCapacity(newLength);
    }
    m_length = newLength;
}

void Mystring::setNewLength(size_t newLength, Mystring s) {
    if (newLength > s.m_capacity) {
        setNewCapacity(newLength, s);
    }
    s.m_length = newLength;
}

//析构函数
Mystring::~Mystring() {
    delete[] m_data;

}












