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
    m_capacity = 0;
    m_length = 0;
    m_data = new char[m_capacity + 1];
    m_data[m_length] = '\0';
}

//拷贝构造函数 copy constructor
Mystring::Mystring(const Mystring &source) {
    //分别设置容量，长度，数据成员指针
    m_length = source.m_length;
    m_capacity = source.m_capacity;
    m_data = new char[m_capacity + 1];
    strcpy(m_data, source.m_data);  //拷贝源字符串
}

//实现 substring constructor
Mystring::Mystring(const Mystring &str, size_t pos, size_t len) {
    //分别设置容量，长度，数据成员指针
    m_length = str.length();
    m_capacity = str.capacity();
    m_data = new char[m_capacity];
    strncpy(m_data, str.m_data + pos, str.length());  //拷贝源字符串
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

//值传递构造函数 from c-string
Mystring::Mystring(const char *s) {
    //判断是否为空
    if (s == nullptr) {
        //创建空字符串
        m_capacity = 0;
        m_length = 0;
        m_data = new char[m_capacity + 1];
        *m_data = '\0';
    } else {
        m_length = strlen(s); //设置容量为源字符串长度
        if (m_length > INT_MAX) {
            m_capacity = INT_MAX; //如果长度超过INT_MAX，则容量设置为INT_MAX
        } else {
            m_capacity = m_length; //否则容量设置为长度
        }
        m_data = new char[m_capacity + 1];  //分配空间
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
unsigned long int Mystring::strtoul(const char *str, char **endptr, int base) {
#define ULONG_MAX ((unsigned long) -1)
    const char *s = str;
    unsigned long acc;
    int c;
    unsigned long maxValueWithoutLastDigit;
    int neg = 0, any, lastDigit;

//跳过空白，c定位到第一个非空白字符，s指向c的下一个字符
    do {
        c = *s++;
    } while (isspace(c));


//    定义正负
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;

    //利用0x前缀判断是16进制
    if ((base == 0 || base == 16) &&
        c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1]; //跳过0x
        s += 2; //跳到c的下一个字符
        base = 16;
    }

//    利用0前缀判断是8进制
    if (base == 0)
        base = c == '0' ? 8 : 10;

    maxValueWithoutLastDigit = neg ? -(unsigned long) LONG_MIN : LONG_MAX; //最大值的前n-1位数
    lastDigit = maxValueWithoutLastDigit % (unsigned long) base; //最大值的最后一位数
    maxValueWithoutLastDigit /= (unsigned long) base;
    //透过这两个变量，我们可以知道，如果输入的数字超过了最大值，那么它的前x位将吻合”最大值的前n-1位“，而且它的最后一位数就会大于“最大值的最后一位数”。

    for (acc = 0, any = 0;; c = *s++) {
        if (isdigit(c))
            c -= '0'; // 如果是数字，则减去'0' ？？？？？
        else if (isalpha(c))
            if (isupper(c)) {
                c -= 'A' - 10;
            } else {
                c -= 'a' - 10;
            } // 如果是字母，则减去字母的值
        else
            break; // 如果不是数字或字母，则跳出循环

        if (c >= base)
            break;

        if (any < 0 || acc > maxValueWithoutLastDigit || (acc == maxValueWithoutLastDigit && c > lastDigit))
            any = -1; //标记为溢出
        else {
            any = 1;    //标记为有效
            acc *= base;    //转换为base进制
            acc += c;    //加上当前的数字
        }
    }

    if (any < 0) {
        acc = neg ? LONG_MIN : LONG_MAX;
        throw "overflow";
    } else if (neg)
        acc = -acc; //如果是负数，则取反
    if (endptr != 0)
        *endptr = (char *) (any ? s - 1 : str); //如果有效，则指向最后一个有效字符，否则指向起始位置

    return (acc); //返回转换后的数字, 大功告成！！！！！！
}

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
void Mystring::reserve(Mystring s, size_t n = 0) {
//    Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
//    If n is 0, this function has no effect.
//    If n is greater than the current capacity, the function increases the capacity to n.
//    If n is less than the current capacity, the function does nothing.
    if (n > m_capacity) {
        char *temp = new char[n + 1];
        setNewCapacity(temp, n);
        strcpy(temp, m_data);
        delete[] m_data;
        m_data = temp;
        m_capacity = n;
    }

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



//运算符重载
Mystring &operator+(const Mystring &left, const Mystring &right) {
    Mystring result;
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

//析构函数
Mystring::~Mystring() {
    delete[] m_data;
}

void Mystring::setNewCapacity(size_t newCapacity) {
    char *temp = new char[newCapacity + 1];
    strcpy(temp, m_data);
    delete[] m_data;
    m_data = temp;
    m_capacity = newCapacity;
}











