#include<bits/stdc++.h>
#define int long long 
using namespace std;
int read(){
	int x=0,f=1;
	char c=0;
	while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c&15);c=getchar();}
	return x*f;
}
int t,n,ans; 
struct node{
	int a,b,c;
}mp[100100];
multiset<int> st[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			mp[i].a=read(),mp[i].b=read(),mp[i].c=read();
			ans+=max({mp[i].a,mp[i].b,mp[i].c});
			if(mp[i].a>=max(mp[i].b,mp[i].c))
				st[0].insert(mp[i].a-max(mp[i].b,mp[i].c));
			else if(mp[i].b>=max(mp[i].a,mp[i].c))
				st[1].insert(mp[i].b-max(mp[i].a,mp[i].c));
			else
				st[2].insert(mp[i].c-max(mp[i].b,mp[i].a));
		}
		n/=2;
		for(int i=0;i<=2;i++){
			while(st[i].size()>n){
				ans-=*st[i].begin();
				st[i].erase(st[i].begin());
			}
			st[i].clear();
		}
		cout<<ans<<"\n";
	}
	return 0;
}


