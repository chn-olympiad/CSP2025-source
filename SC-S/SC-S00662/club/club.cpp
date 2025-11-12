#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
long long t,n,cnt[4],num[N][4],ans;
struct mode{
	long long a[4][3];
	long long id;
}e[N];
struct node{
	long long v,id;
};
bool cmp(node x,node y){return x.v>y.v;}
bool cmp1(mode x,mode y){
	if(x.a[0][1]==y.a[0][1])return x.a[1][1]>y.a[1][1];
	return x.a[0][1]>y.a[0][1];
}
int main(){
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			node k[4];
			cin>>k[0].v>>k[1].v>>k[2].v;
			for(int j=0;j<=2;j++)num[i][j]=k[j].v;
			k[0].id=0,k[1].id=1,k[2].id=2;
			sort(k,k+3,cmp);
			for(int j=0;j<=2;j++)e[i].a[j][0]=k[j].id;
			for(int j=0;j<2;j++)e[i].a[j][1]=k[j].v-k[j+1].v;
			e[i].id=i;
		}
		sort(e+1,e+n+1,cmp1);
		for(int i=1;i<=n;i++){
			long long o=0,u=e[i].id;
			while(cnt[e[i].a[o][0]]>=n/2&&o<=2)o++;
			cnt[e[i].a[o][0]]++;
			ans+=num[u][e[i].a[o][0]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}