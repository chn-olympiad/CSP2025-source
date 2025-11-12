#include<bits/stdc++.h>
using namespace std;
int cnt[20];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)while(cnt[i]--)cout<<i;
	return 0;
}
