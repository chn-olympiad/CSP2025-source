#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=1e5+5;
long long t;
long long n;
long long a[4];
long long vis[N];
struct node{
	long long max_g;
	long long min_g;
	long long w;
}s[N];
bool cmp(node a,node b){
	return a.min_g < b.min_g;
}
void solve(){
	memset(vis,0,sizeof(vis));
	memset(s,0,sizeof(s));
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]>=a[2]&&a[1]>=a[3]){
			s[i].max_g=a[1];
			s[i].min_g=a[1]-max(a[2],a[3]);
			s[i].w=1;
		}
		else if(a[2]>=a[1]&&a[2]>=a[3]){
			s[i].max_g=a[2];
			s[i].min_g=a[2]-max(a[1],a[3]);
			s[i].w=2;
		}
		else{
			s[i].max_g=a[3];
			s[i].min_g=a[3]-max(a[1],a[2]);
			s[i].w=3;
		}
		vis[s[i].w]++,ans+=s[i].max_g;
	}
	sort(s+1,s+1+n,cmp);
	long long max_vis=max(vis[1],max(vis[2],vis[3]));
	long long max_w;
	if(vis[1]>=vis[2]&&vis[1]>=vis[3]) max_w=1;
	else if(vis[2]>=vis[1]&&vis[2]>=vis[3]) max_w=2;
	else max_w=3;
	if(max_vis>n/2){
		max_vis-=n/2;
		long long i=1;
		while(max_vis){
			if(s[i].w==max_w){
				max_vis--;
				ans-=s[i].min_g;
			}
			i++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>t;
	while(t--) solve();
	return 0; 
} 
