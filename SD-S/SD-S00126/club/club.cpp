#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a,b,c,l,ans,len;
vector<ll> v[5];
ll read(){
	ll f=1,w=0;
	char ch=getchar();
	for(;ch<'0' or ch>'9';ch=getchar())if(ch=='-') f=-1;
	for(;ch>='0' and ch<='9';ch=getchar()) w=w*10+ch-'0';
	return f*w;
}
void clean(){v[1].clear(),v[2].clear(),v[3].clear(),l=ans=0;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		clean();
		n=read();
		for(ll i=1;i<=n;i++){
			a=read(),b=read(),c=read();
			if(a>=max(b,c))
				v[1].push_back(max(b,c)-a),ans+=a;
			else if(b>=max(a,c))
				v[2].push_back(max(a,c)-b),ans+=b;
			else if(c>=max(b,a))
				v[3].push_back(max(b,a)-c),ans+=c;
		}for(ll i=1;i<4;i++)if(v[i].size()>n/2) l=i;
		if(l==0){
			cout<<ans<<'\n';
			continue;
		}sort(v[l].begin(),v[l].end());
		len=v[l].size()-1;
		for(ll i=len;i>=n/2;i--) ans+=v[l][i];
		cout<<ans<<'\n';
	}return 0;
}
