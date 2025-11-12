#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;int f=s.size();
	int cnt=0;
	for(int i=0;i<f;i++)
		if(s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt);
	reverse(a+1,a+1+cnt);
	for(int i=1;i<=cnt;i++)
		cout<<a[i];
	return 0;
}
