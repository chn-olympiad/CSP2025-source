#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
typedef pair<int,int> pii;
//priority_queue <pii> q;
int n;
int t;
struct node{
	int dis;
	int a;
	int b;
	int c;
	int ma;
	int maq;
}e[N];
int ans;
int ma[N];
int r[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(r,0,sizeof(r));
		cin>>n;ans=0;
		int tot=0,tot1=0;
		int mmax=n/2;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&e[i].a,&e[i].b,&e[i].c);
			e[i].dis=abs(e[i].a-e[i].b)+abs(e[i].b-e[i].c)+abs(e[i].c-e[i].a);
			e[i].ma=max(e[i].a,max(e[i].b,e[i].c));
			if(e[i].ma==e[i].a)e[i].maq=1;
			if(e[i].ma==e[i].b)e[i].maq=2;
			if(e[i].ma==e[i].c)e[i].maq=3;			
			if(e[i].b==0&&e[i].c==0)tot++;
		}
		if(tot==n){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(e[i].a<e[j].a){
						swap(e[i],e[j]);
					}
				}
			}
			for(int i=1;i<=mmax;i++){
				cout<<e[i].a<<" "<<ans<<'\n';
				ans+=e[i].a;
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(e[i].dis<e[j].dis){
						swap(e[i],e[j]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(r[e[i].maq]<mmax)ans+=e[i].ma,r[e[i].maq]++;
				else if(e[i].maq==1){
					e[i].ma=max(e[i].b,e[i].c);
					if(e[i].ma==e[i].b&&r[2]<mmax)r[2]++;
					else if(e[i].ma==e[i].c&&r[3]<mmax)r[3]++;
					else{
						e[i].ma=e[i].b;
						r[2]++;
					}
					ans+=e[i].ma;
				}
				else if(e[i].maq==2){
					e[i].ma=max(e[i].a,e[i].c);
					if(e[i].ma==e[i].a&&r[1]<mmax)r[1]++;
					else if(e[i].ma==e[i].c&&r[3]<mmax)r[3]++;
					else{
						e[i].ma=e[i].a;
						r[1]++;
					}
					ans+=e[i].ma;
				}
				else if(e[i].maq==3){
					e[i].ma=max(e[i].a,e[i].c);
					if(e[i].ma==e[i].b&&r[2]<mmax)r[2]++;
					else if(e[i].ma==e[i].a&&r[1]<mmax)r[1]++;
					else{
						e[i].ma=e[i].b;
						r[2]++;
					}
					ans+=e[i].ma;
				}
			}
			cout<<ans<<'\n';
		}
	
	}
	return 0;
}
/*
4
4
3 0 0
5 0 0
9 0 0
1 0 0
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

