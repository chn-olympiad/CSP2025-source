#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int nx[n];
    for(int i = 0; i < n; i++){
        cin >> nx;
    }
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            cnt++;
        }
    }
    for(int i = 1; i <= cnt; i++){
        sum *= i;
    }
    cout << sum << endl;
    return 0;
}
