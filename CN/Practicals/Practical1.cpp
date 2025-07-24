#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    char pt[20], ct[20], rpt[20];
    int i, d, e;
    cout << "Enter Plain Text: ";
    cin.getline(pt, 20);  // Modified to accept spaces
    cout << pt;

    d = strlen(pt);
    e = d % 5;

    if (e != 0) {
        for (i = d; i < d + 5 - e; i++) {
            pt[i] = '$';  // Padding with '$'
        }
        pt[i] = '\0';
        cout << "\nThe Plain Text is: " << pt;
    }

    d = strlen(pt);

    for (i = 0; i < d; i = i + 5) {
        ct[i + 2] = pt[i];
        ct[i + 4] = pt[i + 1];
        ct[i] = pt[i + 2];
        ct[i + 1] = pt[i + 3];
        ct[i + 3] = pt[i + 4];
    }
    ct[d] = '\0';

    // Output cipher text without printing '$'
    cout << "\nThe Cipher Text is: ";
    for (i = 0; i < d; i++) {
        if (ct[i] != '$')
            cout << ct[i];
    }

    // Decipher
    for (i = 0; i < d; i = i + 5) {
        rpt[i + 2] = ct[i];
        rpt[i + 3] = ct[i + 1];
        rpt[i] = ct[i + 2];
        rpt[i + 4] = ct[i + 3];
        rpt[i + 1] = ct[i + 4];
    }
    rpt[d] = '\0';

    // Output deciphered text without '$'
    cout << "\nThe De-ciphered Text is: ";
    for (i = 0; i < d; i++) {
        if (rpt[i] != '$')
            cout << rpt[i];
    }

    return 0;
}
