#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+2;
char a[N];
int t;
bool ccp(char aa,char bb){
	return aa>bb;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[++t]=s[i];
	sort(a+1,a+t+1,ccp);
	for(int i=1;i<=t;i++) cout<<a[i];
	return 0;
}