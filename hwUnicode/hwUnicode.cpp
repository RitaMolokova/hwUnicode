#include <iostream> 
#include <tchar.h> 
#include <cstring> 
#define _CRT_SECURE_NO_WARNINGS 
#define _UNICODE 
using namespace std;

bool isPalindrome(const _TCHAR* str) {
    int left = 0, right = _tcslen(str) - 1;
    while (left < right) {
        if (_totlower(str[left]) != _totlower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int countWords(const _TCHAR* str) {
    int count = 0;
    bool inWord = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (_istspace(str[i])) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    return count;
}

void replaceSubstring(_TCHAR* str, const _TCHAR* oldSub, const _TCHAR* newSub) {
    _TCHAR result[1000];
    int resIdx = 0, strLen = _tcslen(str), oldLen = _tcslen(oldSub), newLen = _tcslen(newSub);
    for (int i = 0; i < strLen;) {
        if (_tcsncmp(&str[i], oldSub, oldLen) == 0) {
            _tcscpy(&result[resIdx], newSub);
            resIdx += newLen;
            i += oldLen;
        }
        else {
            result[resIdx++] = str[i++];
        }
    }
    result[resIdx] = '\0';
    _tcscpy(str, result);
}

int _tmain() {
    const int MAX_LEN = 100;
    _TCHAR input[MAX_LEN];

    cout << "Enter your palindrome: ";
    wcin.getline(input, MAX_LEN);
    wcout << (isPalindrome(input) ? "Palindrome" : "No palindrome") << endl;

    cout << "Enter your phrase: ";
    wcin.getline(input, MAX_LEN);
    wcout << "Word count: " << countWords(input) << endl;

    _TCHAR oldSub[MAX_LEN], newSub[MAX_LEN];
    cout << "Enter text: ";
    wcin.getline(input, MAX_LEN);
    cout << "Enter something to find: ";
    wcin.getline(oldSub, MAX_LEN);
    cout << "Enter something to replace: ";
    wcin.getline(newSub, MAX_LEN);

    replaceSubstring(input, oldSub, newSub);
    wcout << "New text: " << input << endl;

    return 0;
}
