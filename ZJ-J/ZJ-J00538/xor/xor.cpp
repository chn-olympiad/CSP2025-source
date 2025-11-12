#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define endl "\n"
#define N 500005
#define int long long
#define MAX 1145141919810
#define TXYAKIOI 91
using namespace std;
int n,k,sum,total,x,ans;
int a[N][25],ma=-MAX;
int len[N];
struct node{
	int l,r;
}jian[N];
inline bool cmp(node x,node y){return x.l<y.r;}
inline void Enchanted(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	rep(i,1,n){
		cin>>x;
		if(x!=0){
			++total;
			sum=0;
			while(x){
				a[total][++sum]=x%2;
				x/=2;
			}
			len[total]=sum;
			ma=max(ma,sum);
		}
	}
//	cout<<ma<<endl;
//	rep(i,1,total){
//		rep(j,1,ma)
//			cout<<a[i][j];
//		cout<<endl;
//	}
	rep(i,1,total)
		rep(j,1,ma)
			a[i][j]+=a[i-1][j];
	x=0;
	rep(i,1,n)
		rep(j,i,n){	
			int s=1,aa=0;
			rep(k,1,ma){
				aa+=(a[j][k]-a[i-1][k])%2*s;
				s*=2;
			}
			if(aa==k){
				jian[++x].l=i;
				jian[x].r=j;
			}
		}
//	rep(i,1,x)
//		cout<<jian[i].l<<' '<<jian[i].r<<endl;
	ans=x;
	sort(jian+1,jian+x+1,cmp);
	int l=jian[1].l,r=jian[1].r;
	rep(i,2,x)
		if(l<=jian[i].l&&jian[i].l<=r&&r<=jian[i].l){
			--ans;
			l=jian[i].l;
			r=jian[i].r;
		}
	cout<<ans;
}
signed main(){Enchanted();return 0;}

