#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5;
int t,n,m,dc[5];
struct cvb { int num,id; } w[5],a[N*2][5],dv[5];
bool xcv(cvb u,cvb v) { return u.num>v.num; }
bool cmp(cvb u,cvb v) { return u.num<v.num; }
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;m=n/2;
		int ans=0;
		memset(dc,0,sizeof(dc));
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				cin>>a[i][j].num,w[j]=(cvb){a[i][j].num,j};
			sort(w,w+3,xcv);
			for(int j=0;j<3;j++)
				a[i][w[j].id]=(cvb){w[j].num,j};
			dv[i]=(cvb){w[0].num-w[1].num,i};
			ans+=w[0].num;dc[w[0].id]++;
		}
		int q=10;
		for(int j=0;j<3;j++) if(dc[j]>m) q=j;
		if(q!=10){
			int qq=dc[(q+2)%3]>dc[(q+4)%3]?(q+4)%3:(q+2)%3;
			sort(dv+1,dv+1+n,cmp);
			for(int i=1;dc[q]>m&&i<=n;i++){
				int now=dv[i].id;
				if(a[now][q].id!=0) continue;
				int nex;
				if(a[now][(q+2)%3].num>a[now][(q+4)%3].num)
					nex=(q+2)%3;
				else nex=(q+4)%3;
				ans-=dv[i].num;dc[q]--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
