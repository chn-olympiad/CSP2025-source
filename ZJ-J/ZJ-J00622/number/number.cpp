#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,t,a[1000010];
string s;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	sort(a+1,a+1+t,cmp);
	if(a[1]==0) cout<<0;
	else
		for(i=1;i<=t;i++) cout<<a[i];
}
