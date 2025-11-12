#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000010],n;
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
	if('0'<=s[i]&&s[i]<='9')a[++n]=s[i]-'0';
	sort(a+1,a+1+n,cmp);
	if(a[1]==0)printf("0");
	else for(int i=1;i<=n;++i)printf("%lld",a[i]);
}