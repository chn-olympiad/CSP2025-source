#include<bits/stdc++.h>
using namespace std;

const int maxn=505;
const int mod=998244353;

int n,m;
char s[maxn];

int c[maxn];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}

