#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e6+5;
string s;
char a[N];
int n,m;
bool cmp(char b,char c){
	return b>c;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9') a[++m]=s[i];
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++) cout<<a[i];
	return 0;
}
