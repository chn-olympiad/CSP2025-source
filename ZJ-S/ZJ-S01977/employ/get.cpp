#include <bits/stdc++.h>
using namespace std;
char pro[1005] = "employ";
int main() {
    freopen("test.sh", "w", stdout);
    for(int i : {1, 2, 3, 4, 5}) {
        printf("cp %s%d.in %s.in\n", pro, i, pro);
        printf("./%s\n", pro);
        printf("diff %s%d.ans %s.out -wqs\n", pro, i, pro);
    }
    return 0;
}