#include <iostream>
#define END cout.flush(); fclose(stdin); fclose(stdout);
using namespace std;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    END;
    return 0;
}
