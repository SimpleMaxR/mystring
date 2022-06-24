//
// Created by Hugo-PC on 5/6/2022.
//

#include "test.h"
#include "mystring.h"
#include <iostream>

using namespace std;

void test::printLine() {
    cout << "-------------------------------" << endl;
    cout << '\n';
}

void test::test_inputoutput() {
    Mystring s1;
    cin >> s1;
    cout << s1 << endl;
}

void test::test_constructor() {
    printLine();
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
    printLine();
}

void test::test_memcpy() {
    printLine();
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
    printLine();
}

//TODO 加号运算符未重载
void test::test_memmove() {
    printLine();
    Mystring s1 = "memmove can be very useful......";
    s1.memmove(s1.c_str() + 15, s1.c_str() + 20, +15);
    cout << "s1: " << s1;
    printLine();
}

void test::test_stoi() {
    printLine();
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

    cout << "str_dec: " << str_dec << " --> " << "i_dec: " << i_dec << endl;
    cout << "str_hex: " << str_hex << "-->" << "i_hex: " << i_hex << '\n';
    cout << "str_bin: " << str_bin << "-->" << "i_bin: " << i_bin << '\n';
    cout << "str_auto: " << str_auto << "-->" << "i_auto: " << i_auto << '\n';

    cout << "end test_stoi" << endl;
    printLine();
}

void test::test_stol() {
    printLine();
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

    cout << "str_dec: " << str_dec << " --> " << "i_dec: " << i_dec << endl;
    cout << "str_hex: " << str_hex << "-->" << "i_hex: " << i_hex << '\n';
    cout << "str_bin: " << str_bin << "-->" << "i_bin: " << i_bin << '\n';
    cout << "str_auto: " << str_auto << "-->" << "i_auto: " << i_auto << '\n';
    printLine();
}


void test::test_strcpy() {
    printLine();

    Mystring forTest;
    char szSource[] = "Hello World";
    char szDestination[20];
    forTest.strcpy(szDestination, szSource);
    printf("%s\n", szDestination);

    printLine();

}

void test::test_strncpy() {
    printLine();


    Mystring forTest;
    char szSource[] = "Hello World";
    char szDestination[20];
    forTest.strncpy(szDestination, szSource, 7);
    printf("%s\n", szDestination);

    printLine();

}

void test::test_strcat() {
    printLine();

    Mystring forTest;
    char szSource[] = "Hello World";
    char szDestination[20] = "the word is ";
    forTest.strcat(szDestination, szSource);
    printf("%s\n", szDestination);
    printLine();

}

void test::test_strncat() {
    printLine();

    Mystring forTest;
    char szSource[] = "Hello World";
    char szDestination[20];
    forTest.strcpy(szDestination, "Hello");
    forTest.strncat(szDestination, szSource, 7);
    printf("%s\n", szDestination);
    printLine();

}

void test::test_memcmp() {
    printLine();

    Mystring forTest;

    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";
    int n;

    n = forTest.memcmp(buffer1, buffer2, sizeof(buffer1));

    if (n > 0) printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
    else if (n < 0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
    else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
    printf("\n");
    printLine();

}

void test::test_strncmp() {
    printLine();

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
    printLine();

}

void test::test_strxfrm() {
    printLine();

    Mystring forTest;
    char dest[20];
    char src[20];
    int len;

    forTest.strcpy(src, "W3C School");
    len = forTest.strxfrm(dest, src, 20);

    printf("the length of |%s| is: |%d|", dest, len);
    printf("\n");
    printLine();

}

void test::test_memchr() {
    printLine();

    Mystring forTest;
    char str[] = "Hello World";
    char key = 'o';
    char *ret = (char *) forTest.memchr(str, key, sizeof(str));
    cout << "word after 'o': " << ret << endl;
    printLine();

}

void test::test_strchr() {
    printLine();

    Mystring forTest;

    const char str[] = "hello world";
    const char ch = 'e';
    char *ret;

    ret = forTest.strchr(str, ch);

    cout << "word after 'e' is " << ret << endl;
    printLine();

}

void test::test_strcspn() {
    printLine();

    Mystring forTest;
    const char str[] = "hello world";
    const char str2[] = "rld";
    size_t ret;

    ret = forTest.strcspn(str, str2);

    cout << "the first pair word is in : " << ret + 1 << endl;
    printLine();
}

void test::test_strpbrk() {
    printLine();

    Mystring forTest;
    char *const str = "abcde2fghi3jk4l";
    const char *const str2 = "34";
    char *ret;

    ret = forTest.strpbrk(str, str2);

    cout << "the first pair word is in : " << *ret << endl;
    printLine();

}

void test::test_append() {
    printLine();


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

    printLine();
}

void test::test_strrchr() {
    printLine();

    Mystring forTest;
    const char str[] = "hello eason!";
    const char ch = 'e';
    char *ret;

    ret = forTest.strrchr(str, ch);

    cout << "test for strrchr" << endl;
    cout << "words in " << str << "after 'e' is " << ret << endl;
    printLine();

}

void test::test_strspn() {
    printLine();

    Mystring forTest;
    int len;
    const char str1[] = "ABCDEFG019874";
    const char str2[] = "ABCD";

    len = forTest.strspn(str1, str2);

    cout << "first pair range's length is " << len << endl;

    printLine();
}

void test::test_strstr() {
    printLine();

    Mystring forTest;
    const char str[] = "hello world";
    const char str2[] = "world";

    char *ret = forTest.strstr(str, str2);

    cout << "the substr is " << ret << endl;
    printLine();

}

void test::test_strtok() {
    printLine();

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
    printLine();

}

void test::test_operator() {
    printLine();

    cout << "test operator +" << endl;
    Mystring firstlevel("cplusplus");
    Mystring secondlevel(".com");

    cout << "firstlevel: " << firstlevel << endl;
    cout << "secondlevel: " << secondlevel << endl;
    cout << "firstlevel + secondlevel: " << firstlevel + secondlevel << endl;
    cout << "------------------------" << endl;

    cout << "test operator =" << endl;
    Mystring str1("cplusplus");
    Mystring str2("c++");

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str1 = str2: " << (str1 = str2) << endl;
    cout << "------------------------" << endl;

    cout << "test operator ==" << endl;
    Mystring str3("cplusplus");
    Mystring str4("cplusplus");
    Mystring str5("Java");

    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;
    cout << "str5: " << str5 << endl;
    cout << "str3 == str4: " << (str3 == str4) << endl;
    cout << "str3 == str5: " << (str3 == str5) << endl;
    cout << "------------------------" << endl;

    cout << "test operator != " << endl;
    cout << "cplusplus != cplusplus: " << (str3 != str4) << endl;
    cout << "cplusplus != Java: " << (str3 != str5) << endl;
    cout << "------------------------" << endl;

    cout << "test operator <" << endl;
    cout << "cplusplus < cplusplus: " << (str3 < str4) << endl;
    cout << "cplusplus < Java: " << (str3 < str5) << endl;
    cout << "------------------------" << endl;

    cout << "test operator >" << endl;
    cout << "cplusplus > cplusplus: " << (str3 > str4) << endl;
    cout << "cplusplus > Java: " << (str3 > str5) << endl;
    cout << "------------------------" << endl;

    cout << "test operator <=" << endl;
    cout << "cplusplus <= cplusplus: " << (str3 <= str4) << endl;
    cout << "cplusplus <= Java: " << (str3 <= str5) << endl;
    cout << "------------------------" << endl;

    cout << "test operator >=" << endl;
    cout << "cplusplus >= cplusplus: " << (str3 >= str4) << endl;
    cout << "cplusplus >= Java: " << (str3 >= str5) << endl;
    cout << "------------------------" << endl;

    cout << "test operator []" << endl;
    Mystring str6("cplusplus");
    cout << "str6: " << str6 << endl;
    cout << "str6[0]: " << str6[0] << endl;
    cout << "str6[1]: " << str6[1] << endl;
    cout << "str6[2]: " << str6[2] << endl;
    cout << "------------------------" << endl;

    cout << "test operator []=" << endl;
    Mystring str7("cplusplus");
    cout << "str7: " << str7 << endl;
    cout << "str7[0] = 'J': " << (str7[0] = 'J') << endl;
    cout << "str7[1] = 'a': " << (str7[1] = 'a') << endl;
    cout << "str7[2] = 'v': " << (str7[2] = 'v') << endl;
    cout << "str7[3] = 'a': " << (str7[3] = 'a') << endl;
    cout << "new str7: " << str7 << endl;
    cout << "------------------------" << endl;

}


void test::test_size() {
    printLine();

    Mystring str("Test string");
    cout << "The size of str is " << str.size() << " bytes.\n";
    cout << "The length of str is " << str.length() << '\n';
    cout << "The MaxSize of str is " << str.max_size() << '\n';
    cout << "The capacity of str is " << str.capacity() << '\n';\
    printLine();

}

void test::test_resize() {
    printLine();

    Mystring str("I like to code in C");
    cout << str << '\n';

    unsigned sz = str.size();

    str.resize(sz + 2, '+');
    cout << str << '\n';

    str.resize(14, '\0');
    cout << str << '\n';
    printLine();

}


void test::test_reserve() {
    printLine();

    Mystring str("Test");
    cout << "capasity of str before reserve is " << str.capacity() << '\n';
    str.reserve(28);
    cout << "capasity of str after reserve(28) is " << str.capacity() << '\n';
    printLine();

}

void test::test_clear() {
    printLine();

    char c;
    Mystring str("Test");
    cout << "Original str: " << str << '\n';

    str.clear();
    cout << "After clear str: " << str << '\n';
    printLine();

}

void test::test_empty() {
    printLine();

    Mystring content("I am not empty");
    Mystring nothing;
    cout << "content is " << content << '\n';
    cout << "nothing is " << nothing << '\n';

    cout << "is content empty ? : " << (content.empty()) << '\n';
    cout << "is nothing empty ? : " << (nothing.empty()) << '\n';
    printLine();

}

void test::test_shrink_to_fit() {
    printLine();

    Mystring str(100, 'x');
    std::cout << "1. capacity of str: " << str.capacity() << '\n';

    str.resize(10);
    std::cout << "2. capacity of str use resize(10): " << str.capacity() << '\n';

    str.shrink_to_fit();
    std::cout << "3. capacity of str use shrink_to_fit: " << str.capacity() << '\n';

    printLine();
}

void test::test_at() {
    printLine();

    Mystring str("Hello World");
    for (unsigned i = 0; i < str.length(); ++i) {
        cout << "char at " << i << " is " << str.at(i) << endl;
    }
    printLine();

}

void test::test_back() {
    printLine();

    Mystring str("hello world.");

    cout << "Original string: " << str << endl;
    cout << "The last char is: " << str.back() << endl;

    str.back() = '!';

    cout << "New string after change the last char to !: " << str << endl;
    printLine();
}

void test::test_front() {
    printLine();

    Mystring str("test string");

    cout << "Original string: " << str << endl;
    cout << "The first char is: " << str.front() << endl;

    str.front() = 'T';

    cout << "New string after change the first char to T: " << str << endl;
    printLine();

}

void test::test_push_back() {
    printLine();

    Mystring str("hello world.");

    cout << "Original string: " << str << endl;
    str.push_back('!');
    cout << "New string after push_back '!': " << str << endl;
    printLine();

}

void test::test_assign() {
    printLine();
    Mystring str("hello world.");

    cout << "Original string: " << str << endl;
    str.assign(str, "test string");
    cout << "New string after assign 'test string': " << str << endl;
    printLine();
}

void test::test_insert() {
    printLine();

    Mystring str = "to be question";
    Mystring str2 = "the ";
    Mystring str3 = "or not to be";

    str.insert(6, str2, str);                 // to be (the )question
    cout << "str.insert(6,str2,str): " << str << endl;
    str.insert(str, 6, str3, 3, 4);             // to be (not )the question
    cout << "str.insert(str,6,str3,3,4): " << str << endl;
    str.insert(str, 10, "to be ");            // to be not (to be )that is the question
    cout << "str.insert(str,10,\"to be \"): " << str << endl;
    std::cout << str << '\n';
    printLine();
}

void test::test_erase() {
    printLine();

    Mystring str("This is an example sentence.");
    std::cout << str << '\n';
    // "This is an example sentence."
    str.erase(10, 8);                        //            ^^^^^^^^
    std::cout << str << '\n';
    // "This is an sentence."

    printLine();
}

void test::test_replace() {
    printLine();

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

    printLine();
}

void test::test_popback() {
    printLine();

    Mystring str("hello world!");
    cout << "Original string: " << str << endl;

    str.pop_back();
    cout << "string after call pop_back()" << str << '\n';

    printLine();
}

void test::test_c_str() {
    printLine();

    Mystring str("hello world!");
    cout << "Original string: " << str << endl;

    cout << "str.c_str() = " << str.c_str() << '\n';

    printLine();
}

void test::test_data() {
    printLine();

    Mystring str("hello world!");
    cout << "Original string: " << str << endl;

    cout << "str.data() = " << str.data() << '\n';

    printLine();
}

void test::test_copy() {
    printLine();

    char *buffer;
    Mystring str("Test string...");
    cout << "Original string: " << str << endl;

    size_t length = str.copy(str, buffer, 6, 5);
    buffer[length] = '\0';

    cout << "after call str.copy(str, buffer, 6, 5): " << endl;
    std::cout << "buffer contains: " << buffer << '\n';

    printLine();
}

void test::test_find() {
    printLine();

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
    printLine();
}

void test::test_rfind() {
    printLine();

    Mystring str("The sixth sick sheik's sixth sheep's sick.");
    Mystring key("sixth");

    size_t found = str.rfind(key);
    cout << "found: " << found << '\n';
    cout << '\n';

    printLine();
}

void test::test_find_first_of() {
    printLine();

    Mystring str("Please, replace the vowels in this sentence by asterisks.");
    size_t found = str.find_first_of("aeiou", 0);
    while (found != std::string::npos) {
        str[found] = '*';
        found = str.find_first_of("aeiou", found + 1);
    }

    std::cout << str << '\n';

    printLine();
}

void test::test_find_last_of() {
    printLine();

    Mystring str1("/usr/bin/man");
    std::cout << "Splitting: " << str1 << '\n';
    std::size_t found = str1.find_last_of("/");
    std::cout << " path: " << str1.substr(0, found + 1) << '\n';
    std::cout << " file: " << str1.substr(found + 1) << '\n';

    Mystring str2("c:/windows/winhelp.exe");
    std::cout << "Splitting: " << str2 << '\n';
    std::size_t found2 = str2.find_last_of("/\\");
    std::cout << " path: " << str2.substr(0, found2) << '\n';
    std::cout << " file: " << str2.substr(found2 + 1) << '\n';

    printLine();
}

void test::test_find_first_not_of() {
    printLine();

    Mystring str("look for non-alphabetic characters...");

    size_t found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");

    if (found != std::string::npos)
        std::cout << "first non-alphabetic character found at: " << found << '\n';
    {
        cout << "The first non-alphabetic character is " << str[found];
        cout << " at position " << found << '\n';
    }

    printLine();
}

void test::test_substr() {
    printLine();

    Mystring str = "We think in generalities, but we live in details.";

    Mystring str2 = str.substr(3, 5);     // "think"
    cout << "str.substr(3,5): " << str2 << endl;

    printLine();
}

void test::test_compare() {
    printLine();

    Mystring str1("green apple");
    Mystring str2("red apple");

    if (str1.compare(str2) != 0)
        std::cout << str1 << " is not " << str2 << '\n';

    if (str1.compare(6, 5, "apple") == 0)
        std::cout << "still, " << str1 << " is an apple\n";

    if (str2.compare(str2.size() - 5, 5, "apple") == 0)
        std::cout << "and " << str2 << " is also an apple\n";

    if (str1.compare(6, 5, str2, 4, 5) == 0)
        std::cout << "therefore, both are apples\n";

    printLine();
}

void test::test_swap() {
    printLine();

    Mystring buyer("money");
    Mystring seller("goods");

    cout << "Before the swap, buyer has " << buyer;
    cout << " and seller has " << seller << '\n';

    swap(buyer, seller);

    cout << "After the swap, buyer has " << buyer;
    cout << " and seller has " << seller << '\n';

    printLine();
}

void test::test_stoul() {
    printLine();
    cout << "stoul test" << '\n';
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    size_t *p;

    long i_dec = a.stoul(str_dec, p, 0);
    long i_hex = a.stoul(str_hex, nullptr, 16);
    long i_bin = a.stoul(str_bin, nullptr, 2);
    long i_auto = a.stoul(str_auto, nullptr, 0);

    cout << "stoul(\"" << str_dec << "\", nullptr, 0) = " << i_dec << '\n';
    cout << "stoul(\"" << str_hex << "\", nullptr, 16) = " << i_hex << '\n';
    cout << "stoul(\"" << str_bin << "\", nullptr, 2) = " << i_bin << '\n';
    cout << "stoul(\"" << str_auto << "\", nullptr, 0) = " << i_auto << '\n';

    printLine();
}

void test::test_stoll() {
    printLine();
    cout << "stoll test" << '\n';
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    size_t *p;

    long i_dec = a.stoll(str_dec, p, 0);
    long i_hex = a.stoll(str_hex, nullptr, 16);
    long i_bin = a.stoll(str_bin, nullptr, 2);
    long i_auto = a.stoll(str_auto, nullptr, 0);

    cout << "stoll(\"" << str_dec << "\", nullptr, 0) = " << i_dec << '\n';
    cout << "stoll(\"" << str_hex << "\", nullptr, 16) = " << i_hex << '\n';
    cout << "stoll(\"" << str_bin << "\", nullptr, 2) = " << i_bin << '\n';
    cout << "stoll(\"" << str_auto << "\", nullptr, 0) = " << i_auto << '\n';

    printLine();
}

void test::test_stoull() {
    printLine();
    cout << "stoull test" << '\n';
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    size_t *p;

    long i_dec = a.stoull(str_dec, p, 0);
    long i_hex = a.stoull(str_hex, nullptr, 16);
    long i_bin = a.stoull(str_bin, nullptr, 2);
    long i_auto = a.stoull(str_auto, nullptr, 0);

    cout << "stoull(\"" << str_dec << "\", nullptr, 0) = " << i_dec << '\n';
    cout << "stoull(\"" << str_hex << "\", nullptr, 16) = " << i_hex << '\n';
    cout << "stoull(\"" << str_bin << "\", nullptr, 2) = " << i_bin << '\n';
    cout << "stoull(\"" << str_auto << "\", nullptr, 0) = " << i_auto << '\n';

    printLine();
}

void test::test_stof() {
    printLine();
    cout << "stof test" << '\n';
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    float f_dec = a.stof(str_dec, nullptr);
    float f_hex = a.stof(str_hex, nullptr);
    float f_bin = a.stof(str_bin, nullptr);
    float f_auto = a.stof(str_auto, nullptr);

    cout << "stof(\"" << str_dec << "\", nullptr) = " << f_dec << '\n';
    cout << "stof(\"" << str_hex << "\", nullptr) = " << f_hex << '\n';
    cout << "stof(\"" << str_bin << "\", nullptr) = " << f_bin << '\n';
    cout << "stof(\"" << str_auto << "\", nullptr) = " << f_auto << '\n';

    printLine();
}

void test::test_stod() {
    printLine();
    cout << "stod test" << '\n';
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    double d_dec = a.stod(str_dec, nullptr);
    double d_hex = a.stod(str_hex, nullptr);
    double d_bin = a.stod(str_bin, nullptr);
    double d_auto = a.stod(str_auto, nullptr);

    cout << "stod(\"" << str_dec << "\", nullptr) = " << d_dec << '\n';
    cout << "stod(\"" << str_hex << "\", nullptr) = " << d_hex << '\n';
    cout << "stod(\"" << str_bin << "\", nullptr) = " << d_bin << '\n';
    cout << "stod(\"" << str_auto << "\", nullptr) = " << d_auto << '\n';

    printLine();
}

void test::test_stold() {
    printLine();
    cout << "stold test" << '\n';
    Mystring a;
    const char *str_dec = "2001, A Space Odyssey";
    const char *str_hex = "40c3";
    const char *str_bin = "-10010110001";
    const char *str_auto = "0x7f";

    long double ld_dec = a.stold(str_dec, nullptr);
    long double ld_hex = a.stold(str_hex, nullptr);
    long double ld_bin = a.stold(str_bin, nullptr);
    long double ld_auto = a.stold(str_auto, nullptr);

    cout << "stold(\"" << str_dec << "\", nullptr) = " << ld_dec << '\n';
    cout << "stold(\"" << str_hex << "\", nullptr) = " << ld_hex << '\n';
    cout << "stold(\"" << str_bin << "\", nullptr) = " << ld_bin << '\n';
    cout << "stold(\"" << str_auto << "\", nullptr) = " << ld_auto << '\n';

    printLine();
}




