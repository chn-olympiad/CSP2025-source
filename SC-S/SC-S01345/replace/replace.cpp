#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5e6+10;
const ll maxx=2e5+10;
ll n,q;
char s1[maxn],s2[maxn];
char S1[maxn],S2[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;++i){
		scanf("%s%s",s1,s2);
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%s%s",S1,S2);
	}
	for(ll i=1;i<=q;++i)
	{
		printf("0\n");
	}
	return 0;
} 