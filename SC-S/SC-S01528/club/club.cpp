#include<bits/stdc++.h>
using namespace std;
int t, n;
bool flag;
struct node{
	int a[4];
	short f,s,l;
}my[100001];
struct op{
	int renshu[4],ans;
}fz[100001][4];
bool ppppp(node x,node y){
	if(x.a[x.f]!=y.a[y.f])return x.a[x.f]>y.a[y.f];
	else if(x.a[x.s]!=y.a[y.s])return x.a[x.s]>y.a[y.s];
	return x.a[x.l]>y.a[y.l];
}
int main() {
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin>>my[i].a[1]>>my[i].a[2]>>my[i].a[3];
			if(my[i].a[1]>=my[i].a[2]&&my[i].a[3]<=my[i].a[1]){
				my[i].f=1;
				if(my[i].a[2]>=my[i].a[3]){
					my[i].s=2,my[i].l=3;
				}else{
					my[i].l=2,my[i].s=3;
				}
			}else{
				if(my[i].a[1]<=my[i].a[2]&&my[i].a[3]<=my[i].a[2]){
					my[i].f=2;
					if(my[i].a[1]>=my[i].a[3]){
						my[i].s=1,my[i].l=3;
					}else{
						my[i].l=1,my[i].s=3;
					}
				}else{
					if(my[i].a[1]<=my[i].a[3]&&my[i].a[3]>=my[i].a[2]){
						my[i].f=3;
						if(my[i].a[1]>=my[i].a[2]){
							my[i].s=1,my[i].l=2;
						}else{
							my[i].l=1,my[i].s=2;
						}
					}
				}
			}
			if(my[i].a[1]==0&&my[i].a[3]==0)flag=true;
			else flag=false;
		}
		sort(my+1,my+1+n,ppppp);
		if(flag){
			int ans=0;
			for(int i=1;i<=n/2;++i){
				ans+=my[i].a[my[i].f];
			}
			return cout<<ans,0;
		}
		for(int i=1;i<=3;++i){
			fz[0][i].renshu[1]=fz[0][i].renshu[2]=fz[0][i].renshu[3]=n/2;
		}
	//	fz[1][1].ans=my[1].a[1],fz[1][2].ans=my[1].a[2],fz[1][3].ans=my[1].a[3];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				int maxn=-1,maxnn;
				if(fz[i-1][1].renshu[j]){
					if(maxn<fz[i-1][1].ans){
						maxn=fz[i-1][1].ans;
						maxnn=1;
					}else{
						if(maxn==fz[i-1][1].ans&&fz[i-1][1].renshu[j]>fz[i-1][maxn].renshu[j]){
							maxnn=1,maxn=fz[i-1][1].ans;
						}
					}
				}
				if(fz[i-1][2].renshu[j]){
					if(maxn<fz[i-1][2].ans){
						maxnn=2,maxn=fz[i-1][2].ans;
					}else{
						if(maxn==fz[i-1][2].ans&&fz[i-1][2].renshu[j]>fz[i-1][maxn].renshu[j]){
							maxnn=2,maxn=fz[i-1][2].ans;
						}
					}
				}
				if(fz[i-1][3].renshu[j]){
					if(maxn<fz[i-1][3].ans){
						maxnn=3,maxn=fz[i-1][3].ans;
					}else{
						if(maxn==fz[i-1][3].ans&&fz[i-1][3].renshu[j]>fz[i-1][maxn].renshu[j]){
							maxnn=3,maxn=fz[i-1][3].ans;
						}
					}
				}
				fz[i][j].ans=maxn+my[i].a[j];
				for(int k=1;k<=3;++k){
					if(k!=j){
						fz[i][j].renshu[k]=fz[i-1][maxnn].renshu[k];
					}else{
						fz[i][j].renshu[k]=fz[i-1][maxnn].renshu[k]-1;
					}
				}
			//	cout<<i<<' '<<j<<' '<<fz[i][j].ans<<' '<<maxn<<' '<<maxnn<<' '<<fz[i][j].renshu[1]<<' '<<fz[i][j].renshu[2]<<' '<<fz[i][j].renshu[3]<<' '<<fz[i-1][maxnn].renshu[1]<<' '<<fz[i-1][maxnn].renshu[2]<<' '<<fz[i-1][maxnn].renshu[3]<<'\n';				
			}
		}
		cout<<max(fz[n][1].ans,max(fz[n][2].ans,fz[n][3].ans))<<'\n';
	}
	return 0;
}