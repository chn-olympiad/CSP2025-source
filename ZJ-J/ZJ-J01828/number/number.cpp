#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
#ifndef kaFkailoVeyou
    freopen("number.out", "w", stdout);
#endif
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string a;
    cin >> a;
    sort(a.begin(), a.end(), [](char a, char b) {
        return a > b;
    });
    for (auto &it : a) {
        if (it >= '0' && it <= '9') {
            cout << it;
        }
    }
    cout << '\n';
    cout.flush();
    fclose(stdin);
#ifndef kaFkailoVeyou
    fclose(stdout);
#endif
    return 0;
}