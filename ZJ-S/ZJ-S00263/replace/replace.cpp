#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using LL = long long;

const int N = 2e5+5;

vector <pair<string, string>> s;

int n, q;

int querryans(string s1, string s2){
    //对于每一对字符串来说 遍历所有匹配 查看是否成功
    int cnt = 0, t = 0;
    for(int i = 0; i < n; i ++){
        while (true){
            auto x = s1.find(s[i].first, t);
            if(x != s1.npos){
                string ss = s1;
                ss.replace(x, s[i].first.size(), s[i].second);
                if(ss == s2){
                    cnt++;
                }
                t = x+1;
            }else break;
//            cout << x << endl; 
        }
    }
    return cnt;

}

int main(){

    IOS
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    cin >> n >> q;
     for(int i = 0; i < n; i ++){
         string s1, s2;
         cin >> s1 >> s2;
         s.push_back({s1, s2});
     }

     while(q--){
         string s1, s2;
         cin >> s1 >> s2;
//         cout << s1 << " " << s2 << endl;
          LL ans = querryans(s1, s2);

         cout << ans << endl;
     }


    return 0;
}
