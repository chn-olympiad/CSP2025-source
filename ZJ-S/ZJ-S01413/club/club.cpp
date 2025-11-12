#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N = 1e5+10;
int n,ans,k[4];
PII p[4];
struct node{
	int a,b,c;
}g[N];
struct pr{
	int vi,p,id;
};
bool cmp3(pr A,pr B){return A.v > B.v;}
bool cmp1(node A,node B){return A.a > B.a;}
bool cmp2(node A,node B){return abs(A.a-A.b) < abs(B.a-B.b);}
bool cmp(pair<int,int> A,pair<int,int> B){return A.first > B.first; }
void solve();
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; 
	cin>>T;
	while(T--) solve();
	return 0;
}
void solve(){
	cin>>n; ans=0; //cout<<"iiiii\n";
	bool f1=1,f2=1,f3=1;
	k[1]=0,k[2]=0,k[3]=0;
	int st[N][4];
	for(int i=1,a,b,c;i<=n;i++){
		cin>>a>>b>>c;
		g[i]={a,b,c};
		f1=f1&(b==0&&c==0);
		f2=f2&(c==0);
	}
	if(f1){
		sort(g+1,g+n+1,cmp1);
		for(int i=1;i<=n/2;i++) ans+=g[i].a;
	}else if(f2){
//		int k1=0,k2=0;
//		for(int i=1;i<=n;i++){
//			if(g[i].a < g[i].b) k2++,ans+=g[i].b;
//			else k1++,ans+=g[i].a;
//		}
//		if(k1==n/2 && k2==n/2);
//		else{
//			int f0=0,ut = abs(n/2 - k1);
//			if(k1>k2) f0=1;
//			sort(g+1,g+n+1,cmp2);
//			for(int i=1;i<=ut;i++){
//				if(g[i].a > g[i].b && f0==1) ans -= abs(g[i].a - g[i].b);
//				else if(g[i].a < g[i].b && f0==0) ans -= abs(g[i].a - g[i].b);
//			}
//		}
		vector<pr> v;
		bool f[N]={0};
		for(int i=1;i<=n;i++){
			v.push_back({g[i].a,i,1});
			v.push_back({g[i].b,i,2});
		}
		sort(v.begin(),v.end(),cmp3);
		int n,k1=0,k2=0;
		for(int i=1;i<=2*n;i++){
			if(k1 == n/2){
				if(v[i].id == 2){
					if(f[v[i].p]) continue;
					else{
						ans+=v[i].vi;
						f[v[i].p]=1;
					}
				}else continue;
			}else if(k2==n/2){
				if(v[i].id == 1){
					if(f[v[i].p]) continue;
					else{
						ans+=v[i].vi;
						f[v[i].p]=1;
					}
				}else continue;
			}else{	
				if(v[i].id == 1){
					if(f[v[i].p]) continue;
					else{
						ans+=v[i].vi;
						f[v[i].p]=1;
						k1++;
					}
				}
				if(v[i].id == 2){
					if(f[v[i].p]) continue;
					else{
						ans+=v[i].vi;
						f[v[i].p]=1;
						k2++;
					}
				}
			}
		}
	}else if(n==2){
		int a1 = g[1].a;
		int b1 = g[1].b;
		int c1 = g[1].c;
		int a2 = g[2].a;
		int b2 = g[2].b;
		int c2 = g[2].c;
		ans = max(a1+b2,max(a1+c2,max(b1+a2,max(b1+c2,max(c1+a2,c1+b2))))); 
	}
	cout<<ans<<endl;
}
/*

int k1=0,k2=0;
		for(int i=1;i<=n;i++){
			if(g[i].a < g[i].b) k2++,ans+=g[i].b;
			else k1++,ans+=g[i].a;
		}
		if(k1==n/2 && k2==n/2);
		else{
			int f0=0,ut = abs(n/2 - k1);
			if(k1>k2) f0=1;
			sort(g+1,g+n+1,cmp2);
			for(int i=1;i<=ut;i++){
				if(g[i].a > g[i].b && f0==1) ans -= abs(g[i].a - g[i].b);
				else if(g[i].a < g[i].b && f0==0) ans -= abs(g[i].a - g[i].b);
			}
		}
*/