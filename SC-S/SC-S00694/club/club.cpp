#include<bits/stdc++.h>
using namespace std;
struct S{
	long long a,b,c;
	bool operator <(S x){
		return a>x.a;
	}
}o[1000005];
vector<S> v;
long long T,n,z[3],ans;
bool vis[1000005];
void dfs(long long p,long long cnt){
	if(z[0]>n/2||z[1]>n/2||z[2]>n/2)return;
	if(p==n){
		ans=max(ans,cnt);
		return;
	}
	z[0]++;
	dfs(p+1,cnt+o[p].a);
	z[0]--;
	z[1]++;
	dfs(p+1,cnt+o[p].b);
	z[1]--;
	z[2]++;
	dfs(p+1,cnt+o[p].c);
	z[2]--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=z[0]=z[1]=z[2]=0;
		v.clear();
		for(long long i=0,a,b,c;i<n;i++){
			cin>>a>>b>>c;
			o[i]={a,b,c};
			v.push_back({a,0,i});
			v.push_back({b,1,i});
			v.push_back({c,2,i});
		}
		if(n<=18){
			dfs(0,0);
			cout<<ans<<"\n";
			continue;
		}
		memset(vis,0,sizeof(vis));
		sort(v.begin(),v.end());
		for(auto i:v){
			if(vis[i.c])continue;
			if(z[i.b]==n/2)continue;
			z[i.b]++;
			ans+=i.a;
			vis[i.c]=1;
		}
		if(n==2){
			ans=0;
			ans=max(ans,o[0].a+o[1].b);
			ans=max(ans,o[0].a+o[1].c);
			ans=max(ans,o[0].b+o[1].c);
			swap(o[0],o[1]);
			ans=max(ans,o[0].a+o[1].b);
			ans=max(ans,o[0].a+o[1].c);
			ans=max(ans,o[0].b+o[1].c);
		}
		cout<<ans<<"\n";
	}
	return 0;
} 