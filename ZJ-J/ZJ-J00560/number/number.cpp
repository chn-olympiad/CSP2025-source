#include<bits/stdc++.h>
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    sort(s.rbegin(),s.rend());
    for(int i=0;i<(int)s.size();i++)if(isdigit(s[i]))cout<<s[i];
}