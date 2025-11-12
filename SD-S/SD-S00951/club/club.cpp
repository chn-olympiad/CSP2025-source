#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
using namespace std;
const ll N=1e5+10;
struct node{
	ll x,y,z,vis;
}a[N];
ll t,n,ma=-9e18,sum,tmp1,tmp2,tmp3,l,tong2,tong3;
bool cmp1(node a,node b){
	if(a.x!=b.x){
		return a.x>b.x;
	}else if(a.y!=b.y){
		return a.y>b.y;
	}else{
		return a.z>b.z;
	}
}
bool cmp2(node a,node b){
	if(a.x!=b.x){
		return a.x>b.x;
	}else if(a.z!=b.z){
		return a.z>b.z;
	}else{
		return a.y>b.y;
	}
}
bool cmp3(node a,node b){
	if(a.y!=b.y){
		return a.y>b.y;
	}else if(a.x!=b.x){
		return a.x>b.x;
	}else{
		return a.z>b.z;
	}
}
bool cmp4(node a,node b){
	if(a.y!=b.y){
		return a.y>b.y;
	}else if(a.z!=b.z){
		return a.z>b.z;
	}else{
		return a.x>b.x;
	}
}
bool cmp5(node a,node b){
	if(a.z!=b.z){
		return a.z>b.z;
	}else if(a.x!=b.x){
		return a.x>b.x;
	}else{
		return a.y>b.y;
	}
}
bool cmp6(node a,node b){
	if(a.z!=b.z){
		return a.z>b.z;
	}else if(a.y!=b.y){
		return a.y>b.y;
	}else{
		return a.x>b.x;
	}
}
void mem(){
	for(ll i=1;i<=n;i++){
		a[i].vis=0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ma=-9e18,tmp1=n/2,tmp2=n/2,tmp3=n/2;
		for(ll i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			tong2+=a[i].y,tong3+=a[i].z;
		}
		if(!tong2&&!tong3){
			sort(a+1,a+n+1,cmp1);
			l=0;
			while(tmp1--){
				sum+=a[++l].x;
			}
			cout<<sum<<'\n';
		}else if(n==2){
			cout<<max({a[1].x+a[2].y,a[1].x+a[3].y,a[2].x+a[1].y,a[2].x+a[3].y,a[3].x+a[1].y,a[3].x+a[2].y})<<'\n';
		}else{
			sum=0,tmp1=n/2,tmp2=n/2,tmp3=n/2,mem();
			sort(a+1,a+n+1,cmp1);
			for(ll i=1;i<=n;i++){
				ll v=max({a[i].x,a[i].y,a[i].z});
				if(a[i].vis) continue;
				if(v==a[i].x&&tmp1){
					tmp1--;
					sum+=v;
				}else if(v==a[i].y&&tmp2){
					tmp2--;
					sum+=v;
				}else if(v==a[i].z&&tmp3){
					tmp3--;
					sum+=v;
				}
				a[i].vis=1;
			}
			ma=max(ma,sum);
			//
			sum=0,tmp1=n/2,tmp2=n/2,tmp3=n/2,mem();
			sort(a+1,a+n+1,cmp2);
			for(ll i=1;i<=n;i++){
				ll v=max({a[i].x,a[i].y,a[i].z});
				if(a[i].vis) continue;
				if(v==a[i].x&&tmp1){
					tmp1--;
					sum+=v;
				}else if(v==a[i].z&&tmp3){
					tmp3--;
					sum+=v;
				}else if(v==a[i].y&&tmp2){
					tmp2--;
					sum+=v;
				}
				a[i].vis=1;
			}
			ma=max(ma,sum);
			//
			sum=0,tmp1=n/2,tmp2=n/2,tmp3=n/2,mem();
			sort(a+1,a+n+1,cmp3);
			for(ll i=1;i<=n;i++){
				ll v=max({a[i].x,a[i].y,a[i].z});
				if(a[i].vis) continue;
				if(v==a[i].y&&tmp2){
					tmp2--;
					sum+=v;
				}else if(v==a[i].x&&tmp1){
					tmp1--;
					sum+=v;
				}else if(v==a[i].z&&tmp3){
					tmp3--;
					sum+=v;
				}
				a[i].vis=1;
			}
			ma=max(ma,sum);
			//
			sum=0,tmp1=n/2,tmp2=n/2,tmp3=n/2,mem();
			sort(a+1,a+n+1,cmp4);
			for(ll i=1;i<=n;i++){
				ll v=max({a[i].x,a[i].y,a[i].z});
				if(a[i].vis) continue;
				if(v==a[i].y&&tmp2){
					tmp2--;
					sum+=v;
				}else if(v==a[i].z&&tmp3){
					tmp3--;
					sum+=v;
				}else if(v==a[i].x&&tmp1){
					tmp1--;
					sum+=v;
				}
				a[i].vis=1;
			}
			ma=max(ma,sum);
			//
			sum=0,tmp1=n/2,tmp2=n/2,tmp3=n/2,mem();
			sort(a+1,a+n+1,cmp5);
			for(ll i=1;i<=n;i++){
				ll v=max({a[i].x,a[i].y,a[i].z});
				if(a[i].vis) continue;
				if(v==a[i].z&&tmp3){
					tmp3--;
					sum+=v;
				}else if(v==a[i].x&&tmp1){
					tmp1--;
					sum+=v;
				}else if(v==a[i].y&&tmp2){
					tmp2--;
					sum+=v;
				}
				a[i].vis=1;
			}
			ma=max(ma,sum);
			//
			sum=0,tmp1=n/2,tmp2=n/2,tmp3=n/2,mem();
			sort(a+1,a+n+1,cmp6);
			for(ll i=1;i<=n;i++){
				ll v=max({a[i].x,a[i].y,a[i].z});
				if(a[i].vis) continue;
				if(v==a[i].z&&tmp3){
					tmp3--;
					sum+=v;
				}else if(v==a[i].y&&tmp2){
					tmp2--;
					sum+=v;
				}else if(v==a[i].x&&tmp1){
					tmp1--;
					sum+=v;
				}
				a[i].vis=1;
			}
			ma=max(ma,sum);
			//
			cout<<ma<<'\n';
		}
	}
	return 0;
}
/*
1
6
1 0 0
3 0 0
5 0 0
9 0 0
7 0 0
114514 0 0

114530
----------------
3
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

18
4
13
*/
