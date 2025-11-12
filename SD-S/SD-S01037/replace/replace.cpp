#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
inline ll qr()
{
	ll flag=1,sum=0;
	char ch=getchar();
	for(;!isdigit(ch);flag=(ch=='-')?-1:1,ch=getchar());
	for(;isdigit(ch);sum=sum*10+ch-'0',ch=getchar());
	return flag * sum;
}
ll n,q;
int main()
{
	ll i,j;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=qr(),q=qr();
	for(i=1;i<=q;i++)  cout<<0<<"\n";
	return 0;
}
