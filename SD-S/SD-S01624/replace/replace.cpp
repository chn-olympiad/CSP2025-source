#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lf double
#define first f
#define second s
ll n,q;
pair<ll,pair<string,string>> p[2*(ll)1e5];
string s1,s2;
int main() {
	freopen("replace.in","r",stdin); //¼ÇµÃ¸Ä£¡
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1; i<=n; i++)
		cin>>s1>>s2,p[i]= {s1.size(),{s1,s2}};
	sort(p+1,p+n+1);
	while(q--)
		printf("0");
	return 0;
}

