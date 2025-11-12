#include <bits/stdc++.h>
using namespace std;

struct stu{
    int p1, p2;
};

bool cmp(const stu& a, const stu& b){
    if (a.p1 == b.p1){
        return a.p2 < b.p2;
    }
    return a.p1 > b.p1;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int t2;
        stu student[n];
        for (int i = 0; i < n; i++){
            cin >> student[i].p1 >> student[i].p2 >> t2;
        }
        sort(student, student+n, cmp);
        int ans = 0;
        for (int i = 0; i < n/2; i++){
            ans += student[i].p1;
        }
        for (int i = n/2; i < n; i++){
            ans += student[i].p2;
        }
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
