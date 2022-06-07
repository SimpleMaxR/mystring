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

void test::test_copyConstructor() {
    Mystring s1("Hello");
    Mystring s2(s1);
    cout << s2 << endl;
}

void test::test_memcpy() {
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

}

//TODO 加号运算符未重载
void test::test_memmove() {
//    Mystring s1 = "memmove can be very useful......";
//    s1.memmove(s1 + 15, s1 + 20, +15);
//    puts (str);
//    return 0;
}

void test::test_stoi() {
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

    char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
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


}

void test::test_strrchr() {

}




