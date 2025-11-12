#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
string s;
int num[15];
int main(){
//	freopen()ni bei pian le
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	IOS;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;++i)
		if(s[i]>='0'&&s[i]<='9')
			++num[s[i]-'0'];
	for(int i=9;i>=0;--i)for(int j=1;j<=num[i];++j)cout<<i;
	cout<<endl;
	return 0;
}
//mei bi yao dui pai