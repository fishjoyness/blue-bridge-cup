#include <iostream>
using namespace std;

int main() {
    char ch = 'A'; // ´óÐ´×ÖÄ¸
    char converted_ch;

    // ¼ì²é×Ö·ûÊÇ·ñÔÚ´óÐ´×ÖÄ¸µÄ ASCII ·¶Î§ÄÚ
    if (ch >= 'A' && ch <= 'Z') {
        // ´óÐ´×ÖÄ¸×ª»»ÎªÐ¡Ð´×ÖÄ¸ (ASCIIÂë + 32)
        converted_ch = ch + 32;
        cout << "Converted character: " << converted_ch << endl;
    } 
    // ¼ì²é×Ö·ûÊÇ·ñÔÚÐ¡Ð´×ÖÄ¸µÄ ASCII ·¶Î§ÄÚ
    else if (ch >= 'a' && ch <= 'z') {
        // Ð¡Ð´×ÖÄ¸×ª»»Îª´óÐ´×ÖÄ¸ (ASCIIÂë - 32)
        converted_ch = ch - 32;
        cout << "Converted character: " << converted_ch << endl;
    } 
    else {
        cout << "Invalid character!" << endl;
    }

    return 0;
}

