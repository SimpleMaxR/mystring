//
// Created by Hugo-PC on 5/6/2022.
//

#include "test.h"
#include "mystring.h"
#include <iostream>
using namespace std;

void test::test_inputoutput() {
    Mystring s1;
    cin >> s1;
    cout << s1 << endl;
}

void test::test_constructor() {
    Mystring s1;
    Mystring s2("Hello");
    Mystring s3(s2);
    Mystring s4(s2, 1, 3);
    Mystring s5(s2, 1);
    Mystring s6(2, 'a');
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;
    cout << "s6: " << s6 << endl;
}

void test::test_memcpy() {
    cout << "test_memcpy" << endl;

    struct {
        char name[40];
        int age;
    } person, person_copy;

    char myname[] = "Pierre de Fermat";
    Mystring s1;    // empty object

    /* using memcpy to copy string: */
    s1.memcpy(person.name, myname, s1.strlen(myname) + 1);
    person.age = 46;

    /* using memcpy to copy structure: */
    s1.memcpy(&person_copy, &person, sizeof(person));

    printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

    cout << "end test_memcpy" << endl;
}

//TODO 加号运算符未重载
void test::test_memmove() {
//    Mystring s1 = "memmove can be very useful......";
//    s1.memmove(s1 + 15, s1 + 20, +15);
//    puts (str);
//    return 0;
}

void test::test_stoi() {
    cout << "test_stoi" << endl;

    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    size_t *p;

    int i_dec = a.stoi(str_dec, p, 0);
    int i_hex = a.stoi(str_hex, nullptr, 16);
    int i_bin = a.stoi(str_bin, nullptr, 2);
    int i_auto = a.stoi(str_auto, nullptr, 0);

//    cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n"; //TODO substr未完成
    cout << str_hex << ": " << i_hex << '\n';
    cout << str_bin << ": " << i_bin << '\n';
    cout << str_auto << ": " << i_auto << '\n';

    cout << "end test_stoi" << endl;
}

void test::test_stol() {
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    size_t *p;

    long i_dec = a.stol(str_dec, p, 0);
    long i_hex = a.stol(str_hex, nullptr, 16);
    long i_bin = a.stol(str_bin, nullptr, 2);
    long i_auto = a.stol(str_auto, nullptr, 0);
}

void test::test_strtol() {

    char szNumbers[] = "2001 0x60c0c0 -1101110100110100100000 0x6fffff";
    char *pEnd;
    long int li1, li2, li3, li4;
    li1 = li2 = li3 = li4 = 0;
    li1 = strtol(szNumbers, &pEnd, 10);
    li2 = strtol(pEnd, &pEnd, 16);
    li3 = strtol(pEnd, &pEnd, 2);
    li4 = strtol(pEnd, NULL, 0);
    printf("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
}

void test::test_strcpy() {
    Mystring forTest;
    char szSource[] = "Hello World";
    char szDestination[20];
    forTest.strcpy(szDestination, szSource);
    printf("%s\n", szDestination);
}

void test::test_strncpy() {
    Mystring forTest;
    char szSource[] = "Hello World";
    char szDestination[20];
    forTest.strncpy(szDestination, szSource, 7);
    printf("%s\n", szDestination);
}

void test::test_strcat() {
    Mystring forTest;
    char szSource[] = "Hello World";
    char szDestination[20] = "the word is ";
    forTest.strcat(szDestination, szSource);
    printf("%s\n", szDestination);
}

void test::test_strncat() {
    Mystring forTest;
    char szSource[] = "Hello World";
    char szDestination[20];
    forTest.strcpy(szDestination, "Hello");
    forTest.strncat(szDestination, szSource, 7);
    printf("%s\n", szDestination);
}

void test::test_memcmp() {
    Mystring forTest;

    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";
    int n;

    n = forTest.memcmp(buffer1, buffer2, sizeof(buffer1));

    if (n > 0) printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
    else if (n < 0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
    else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
    printf("\n");
}

void test::test_strncmp() {
    Mystring forTest;
    char str1[15];
    char str2[15];
    int ret;


    forTest.strcpy(str1, "abcdef");
    forTest.strcpy(str2, "ABCDEF");

    ret = forTest.strncmp(str1, str2, 4);

    if (ret < 0) {
        printf("str1 smaller than str2");
        printf("\n");
    } else if (ret > 0) {
        printf("str2 smaller than str1");
        printf("\n");
    } else {
        printf("str1 equal to str2");
        printf("\n");
    }
}

void test::test_strxfrm() {
    Mystring forTest;
    char dest[20];
    char src[20];
    int len;

    forTest.strcpy(src, "W3C School");
    len = forTest.strxfrm(dest, src, 20);

    printf("the length of |%s| is: |%d|", dest, len);
    printf("\n");
}

void test::test_memchr() {
    Mystring forTest;
    char str[] = "Hello World";
    char key = 'o';
    char *ret = (char *) forTest.memchr(str, key, sizeof(str));
    cout << "word after 'o': " << ret << endl;
}

void test::test_strchr() {
    Mystring forTest;

    const char str[] = "hello world";
    const char ch = 'e';
    char *ret;

    ret = forTest.strchr(str, ch);

    cout << "word after 'e' is " << ret << endl;
}

void test::test_strcspn() {
    Mystring forTest;
    const char str[] = "hello world";
    const char str2[] = "rld";
    size_t ret;

    ret = forTest.strcspn(str, str2);

    cout << "the first pair word is in : " << ret + 1 << endl;

}

void test::test_strpbrk() {
    Mystring forTest;
    char *const str = "abcde2fghi3jk4l";
    const char *const str2 = "34";
    char *ret;

    ret = forTest.strpbrk(str, str2);

    cout << "the first pair word is in : " << *ret << endl;
}

void test::test_append() {
    Mystring forTest;
    Mystring str = "hello";
    Mystring str2 = "world";
    Mystring str3 = "!";

    cout << "str1: " << str << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << '\n';

    forTest.append(str, str2);
    forTest.append(str, str3);

    cout << "str1 after add str2 & str3 to it's end: " << str << endl;
}

void test::test_strrchr() {
    Mystring forTest;
    const char str[] = "hello eason!";
    const char ch = 'e';
    char *ret;

    ret = forTest.strrchr(str, ch);

    cout << "test for strrchr" << endl;
    cout << "words in " << str << "after 'e' is " << ret << endl;

}

void test::test_strspn() {
    Mystring forTest;
    int len;
    const char str1[] = "ABCDEFG019874";
    const char str2[] = "ABCD";

    len = forTest.strspn(str1, str2);

    cout << "first pair range's length is " << len << endl;
}

void test::test_strstr() {
    Mystring forTest;
    const char str[] = "hello world";
    const char str2[] = "world";

    char *ret = forTest.strstr(str, str2);

    cout << "the substr is " << ret << endl;
}

void test::test_strtok() {
    Mystring forTest;
    char str[80] = "This-is-my-website-120.76.192.132";
    const char s[2] = "-";
    char *token;

    /* 获取第一个子字符串 */
    token = forTest.strtok(str, s);

    /* 继续获取其他的子字符串 */
    while (token != NULL) {
        cout << token << endl;

        token = forTest.strtok(NULL, s);
    }

}

void test::test_operator() {
    //TODO 待实际测试 operator =
    Mystring str1, str2, str3;
    str1 = "Test string: ";   // c-string
    str2 = 'x';               // single character
    str3 = str1 + str2;       // string

    cout << str3 << endl;

    //TODO 待完成定义 operator []

    //TODO 待完成定义 operator +=
}

//TODO change name
void test::test_size() {
    Mystring str("Test string");
    cout << "The size of str is " << str.size() << " bytes.\n";
    cout << "The length of str is " << str.length() << '\n';
    cout << "The MaxSize of str is " << str.max_size() << '\n';
    cout << "The capacity of str is " << str.capacity() << '\n';
}

void test::test_resize() {
    Mystring str("I like to code in C");
    cout << str << '\n';

    unsigned sz = str.size();

    str.resize(sz + 2, '+');
    cout << str << '\n';

    str.resize(14, '\0');
    cout << str << '\n';
}

//TODO bug
void test::test_reserve() {
    Mystring str = ("Test");
    cout << "capasity of str before reserve is " << str.capacity() << '\0';

    str.reserve(str, 28);
    cout << "capasity of str after reserve(28) is " << str.capacity() << '\0';
    cout << str;
}

void test::test_clear() {
    char c;
    Mystring str;
    std::cout << "Please type some lines of text. Enter a dot (.) to finish:\n";
    do {
        c = cin.get();
        str += c;
        if (c == '\n') {
            cout << str;
            str.clear();
        }
    } while (c != '.');
}

void test::test_empty() {
    Mystring content;
    Mystring line;
    std::cout << "Please introduce a text. Enter an empty line to finish:\n";
    do {
//        getline(std::cin,line);
        content += line + '\n';
    } while (!line.empty());
    std::cout << "The text you introduced was:\n" << content;
}

void test::test_shrink_to_fit() {
    Mystring str(100, 'x');
    std::cout << "1. capacity of str: " << str.capacity() << '\n';

    str.resize(10);
    std::cout << "2. capacity of str use resize(10): " << str.capacity() << '\n';

    str.shrink_to_fit();
    std::cout << "3. capacity of str use shrink_to_fit: " << str.capacity() << '\n';
}

void test::test_at() {
    Mystring str("Hello World");
    for (unsigned i = 0; i < str.length(); ++i) {
        cout << "char at " << i << " is " << str.at(i) << endl;
    }
}

void test::test_back() {
    Mystring str("hello world.");

    cout << "Original string: " << str << endl;
    cout << "The last char is: " << str.back() << endl;

    str.back() = '!';

    cout << "New string after change the last char to !: " << str << endl;
}

void test::test_front() {
    Mystring str("test string");

    cout << "Original string: " << str << endl;
    cout << "The first char is: " << str.front() << endl;

    str.front() = 'T';

    cout << "New string after change the first char to T: " << str << endl;
}

void test::test_push_back() {
    Mystring str("hello world.");

    cout << "Original string: " << str << endl;
    str.push_back('!');
    cout << "New string after push_back '!': " << str << endl;
}

void test::test_assign() {
    Mystring str("hello world.");

    cout << "Original string: " << str << endl;
    str.assign(str, "test string");
    cout << "New string after assign 'test string': " << str << endl;
}

void test::test_insert() {
    Mystring str = "to be question";
    Mystring str2 = "the ";
    Mystring str3 = "or not to be";

    //follow the example in the https://m.cplusplus.com/reference/string/string/insert/
    str.insert(6, str2, str);                 // to be (the )question
    cout << "str.insert(6,str2,str): " << str << endl;
    str.insert(str, 6, str3, 3, 4);             // to be (not )the question
    cout << "str.insert(str,6,str3,3,4): " << str << endl;
    str.insert(str, 10, "that is cool", 8);    // to be not (that is )the question
    cout << "str.insert(str,10,\"that is cool\",8): " << str << endl;
    str.insert(str, 10, "to be ");            // to be not (to be )that is the question
    cout << "str.insert(str,10,\"to be \"): " << str << endl;
    str.insert(str, 15, 1, ':');               // to be not to be(:) that is the question
    cout << "str.insert(str,15,1,':'): " << str << endl;

    std::cout << str << '\n';
}

void test::test_erase() {

    Mystring str("This is an example sentence.");
    std::cout << str << '\n';
    // "This is an example sentence."
    str.erase(10, 8);                        //            ^^^^^^^^
    std::cout << str << '\n';
    // "This is an sentence."
}

void test::test_replace() {
    Mystring base = "this is a test string.";
    Mystring str2 = "n example";
    Mystring str3 = "sample phrase";
    Mystring str4 = "useful.";

    // replace signatures used in the same order as described above:

    // Using positions:                 0123456789*123456789*12345
    Mystring str = base;           // "this is a test string."
    cout << "original str: " << str << endl;
    cout << "base: " << base << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;
    cout << '\n';

    str.replace(9, 5, str2);          // "this is an example string." (1)
    cout << "call str.replace(9,5,str2): " << str << endl;

    str.replace(10, 6, str3, 7, 6);     // "this is an example phrase." (2)
    cout << "call str.replace(10,6,str3,7,6): " << str << endl;

    str.replace(8, 10, "just a");     // "this is just a phrase."     (3)
    cout << "call str.replace(8,10,\"just a\"): " << str << endl;

    str.replace(8, 6, "a shorty", 7);  // "this is a short phrase."    (4)
    cout << "call str.replace(8,6,\"a shorty\",7): " << str << endl;

    str.replace(5, 1, 3, '!');        // "this is a short phrase!!!"  (5)
    cout << "call str.replace(22,1,3,'!'): " << str << endl;
}

void test::test_popback() {
    Mystring str("hello world!");
    cout << "Original string: " << str << endl;

    str.pop_back();
    cout << "string after call pop_back()" << str << '\n';
}

void test::test_c_str() {
    Mystring str("hello world!");
    cout << "Original string: " << str << endl;

    cout << "str.c_str() = " << str.c_str() << '\n';
}

void test::test_data() {
    Mystring str("hello world!");
    cout << "Original string: " << str << endl;

    cout << "str.data() = " << str.data() << '\n';
}

void test::test_copy() {
    char *buffer;
    Mystring str("Test string...");
    size_t length = str.copy(str, buffer, 6, 5);
    buffer[length] = '\0';
    std::cout << "buffer contains: " << buffer << '\n';
}

void test::test_find() {
    Mystring str("There are two needles in this haystack with needles.");
    Mystring str2("needle");
    cout << "original string is: " << str << '\n';
    cout << '\n';

    // different member versions of find in the same order as above:
    std::size_t found = str.find(str2);
    if (found != std::string::npos)
        std::cout << "first 'needle' found at: " << found << '\n';

    found = str.find("needles are small", found + 1, 6);
    if (found != std::string::npos)
        std::cout << "second 'needle' found at: " << found << '\n';

    found = str.find("haystack");
    if (found != std::string::npos)
        std::cout << "'haystack' also found at: " << found << '\n';

    found = str.find('.');
    if (found != std::string::npos)
        std::cout << "Period found at: " << found << '\n';

    // let's replace the first needle:
    str.replace(str.find(str2), str2.length(), "preposition");
    std::cout << str << '\n';

}

void test::test_rfind() {
    Mystring str("The sixth sick sheik's sixth sheep's sick.");
    Mystring key("sixth");

    size_t found = str.rfind(key);
    if (found != std::string::npos)
        str.replace(found, key.length(), "seventh,");
    cout << "str after call str.replace (found,key.length(),\"seventh,\");" << '\n';
    cout << str << '\n';
}

void test::test_find_first_of() {
    Mystring str("Please, replace the vowels in this sentence by asterisks.");
    size_t found = str.find_first_of("aeiou", 0);
    while (found != std::string::npos) {
        str[found] = '*';
        found = str.find_first_of("aeiou", found + 1);
    }

    std::cout << str << '\n';

}

void test::test_find_last_of() {

}

void test::test_find_first_not_of() {

    Mystring str("look for non-alphabetic characters...");

    size_t found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");

    if (found != std::string::npos)
        std::cout << "first non-alphabetic character found at: " << found << '\n';
    {
        cout << "The first non-alphabetic character is " << str[found];
        cout << " at position " << found << '\n';
    }
}

void test::test_substr() {

}

void test::test_compare() {

}

void test::test_swap() {

}

void test::test_getline() {

}




