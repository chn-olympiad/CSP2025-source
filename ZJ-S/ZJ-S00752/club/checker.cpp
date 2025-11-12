#include <bits/stdc++.h>
using namespace std;
int main () {
    int tot = 0;
    while (1) {
        system("data.exe > data.txt");
        system("club.exe < data.txt > club.txt");
        system("club2.exe < data.txt > club2.txt");
        if (system("fc club.txt club2.txt")) break;
        tot ++;
        cout << "[Task] " << tot << "\n";
    }
}