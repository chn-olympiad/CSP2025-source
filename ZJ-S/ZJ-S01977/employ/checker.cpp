#include <bits/stdc++.h>
using namespace std;
int main() {
    int ct = 0;
    while(true) {
        system("./data");
        system("./employ");
        system("./bf");
        if(system("diff employ.out test.out > checker.log")) {
            printf("#%d : WA\n", ++ct), exit(0);
        }
        printf("#%d : AC\n", ++ct);
    }
    return 0;
}