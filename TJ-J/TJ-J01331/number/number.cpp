#include<bits/stdc++.h>
using namespace std;
char s[1000005];
vector<char> ans;
bool cmp(int a, int b){return a > b;}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i=0; s[i]!='\0'; ++i)
        if(isdigit(s[i])) ans.push_back(s[i]);
    sort(ans.begin(), ans.end(), cmp);
    for(int i=0; i<ans.size(); ++i) cout << ans[i];
    return 0;
}
