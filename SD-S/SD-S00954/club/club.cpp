#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
struct _{
	int x,y,z;
}g[100005];
vector<int> a,b,c;
int n;
bool cmp1(int x1,int x2){
	_ x=g[x1],y=g[x2];
	return min(x.x-x.y,x.x-x.z)<min(y.x-y.y,y.x-y.z);
}
bool cmp2(int x1,int x2){
	_ x=g[x1],y=g[x2];
	return min(x.y-x.x,x.y-x.z)<min(y.y-y.x,y.y-y.z);
}
bool cmp3(int x1,int x2){
	_ x=g[x1],y=g[x2];
	return min(x.z-x.x,x.z-x.y)<min(y.z-y.x,y.z-y.y);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ll ans=0;
		a.clear();b.clear();c.clear();
		for(int i=1;i<=n;i++){
			cin>>g[i].x>>g[i].y>>g[i].z;
			if(g[i].x>=g[i].y&&g[i].x>=g[i].z){
				a.push_back(i);
				ans+=g[i].x;
			}
			else if(g[i].y>=g[i].x&&g[i].y>=g[i].z){
				b.push_back(i);
				ans+=g[i].y;
			}
			else{
				c.push_back(i);
				ans+=g[i].z; 
			}
		}
		if(a.size()>n/2){
			sort(a.begin(),a.end(),cmp1);
			for(int i=0;a.size()-i>n/2;i++){
				_ tmp=g[a[i]];
				ans-=min(tmp.x-tmp.y,tmp.x-tmp.z);
			}
		}
		else if(b.size()>n/2){
			sort(b.begin(),b.end(),cmp2);
			for(int i=0;b.size()-i>n/2;i++){
				_ tmp=g[b[i]];
				ans-=min(tmp.y-tmp.x,tmp.y-tmp.z);
			}
		}
		else if(c.size()>n/2){
			sort(c.begin(),c.end(),cmp3);
			for(int i=0;c.size()-i>n/2;i++){
				_ tmp=g[c[i]];
				ans-=min(tmp.z-tmp.x,tmp.z-tmp.y);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
