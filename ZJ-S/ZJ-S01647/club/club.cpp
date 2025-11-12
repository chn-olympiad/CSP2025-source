#include <bits/stdc++.h>
using namespace std;

#define N 200010

int n, a[N][4];
vector < int > s1, s2, s3;
int ans;

void check(vector < int > &s){
    vector < int > tmp;
    for(int v : s){
        sort(a[v] + 1, a[v] + 4);
        tmp.push_back(a[v][3] - a[v][2]);
    }
    sort(tmp.begin(), tmp.end()); int len = s.size();
    for(int i = 0;i < len - n / 2;i++)
        ans -= tmp[i];
}

void work(){
    cin >> n; ans = 0; s1.clear(), s2.clear(), s3.clear();
    for(int i = 1;i <= n;i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) s1.push_back(i), ans += a[i][1];
        else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) s2.push_back(i), ans += a[i][2];
        else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) s3.push_back(i), ans += a[i][3];
    }
    if(s1.size() > n / 2) check(s1);
    else if(s2.size() > n / 2) check(s2);
    else if(s3.size() > n / 2) check(s3);
    cout << ans << endl;
    return;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) work();
    return 0;
}