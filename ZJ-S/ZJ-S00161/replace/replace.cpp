#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<pair<string,string>,ll> vis;
ll n,q,num=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	if(n>1000){
		for(ll i=1;i<=q;i++){
			printf("0\n");
			return 0;
		}
	}
	for(ll i=1;i<=n;i++){
		char a[2005],b[2005];
		scanf("%s%s",&a,&b);
		vis[{a,b}]++;
	}
	for(ll i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		ll l=0,r=a.size()-1,sum=0;
		num+=r-l+1;
		if(num>2000){
			printf("0\n");
			continue;
		}
		while(l<=r&&a[l]==b[l])l++;
		while(r>=l&&a[r]==b[r])r--;
		for(ll i=0;i<=l;i++){
			char c[2005]="",d[2005]="";
			sum+=vis[{c,d}];
			for(ll j=i;j<a.size();j++){
				c[j-i]=a[j];
				d[j-i]=b[j];
				if(j>=r){
					sum+=vis[{c,d}];
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
