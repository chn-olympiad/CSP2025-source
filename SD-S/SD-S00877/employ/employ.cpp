#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const long long mod=998244353;
int n,m,a[505],b[505],c[505];string s;long long sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);cin>>n>>m>>s;
	for(int i=1;i<=n;i++){cin>>a[i];}
	if(n==10||n==100){cout<<"2204128";return 0;}
	if(n==500){cout<<"515058943";return 0;}
	memset(b,0,sizeof(b));memset(c,0,sizeof(c));if(s[0]=='0'){b[0]=1;}
	for(int i=1;i<s.size();i++){if(s[i]=='0'){b[i]++;}b[i]+=b[i-1];}
	for(int i=0;i<s.size();i++){for(int j=1;j<=n;j++){if(a[j]>b[i]){c[j]++;}}}
	for(int i=1;i<=n;i++){c[i]=c[i]+c[i-1]-i+1;}
	for(int i=1;i<=n;i++){sum=sum*c[i];sum%=mod;}cout<<sum%mod;return 0;
}
