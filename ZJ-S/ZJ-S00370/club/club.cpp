#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node{
	int ma,md,x,y,z;
}a[N];
struct node1{
	int num,id;
}b[15];
bool cmp(node u,node v){
	if(u.ma-u.md!=v.ma-v.md)return u.ma-u.md>v.ma-v.md;
	else return u.ma>v.ma;
}
bool cmp1(node1 u,node1 v){
	return u.num>v.num;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		int maxx=max({x,y,z}),mid,minn=min({x,y,z});
		mid=x+y+z-maxx-minn;
		a[i]={maxx,mid,x,y,z};
	}
	sort(a+1,a+1+n,cmp);

	int tj[4];
	for(int i=1;i<=3;i++)tj[i]=n/2;
	int ans=0;
	for(int i=1;i<=n;i++){
		int ma=a[i].ma,md=a[i].md,x=a[i].x,y=a[i].y,z=a[i].z;
		b[1]={x,1};
		b[2]={y,2};
		b[3]={z,3};
		sort(b+1,b+4,cmp1);
		for(int j=1;j<=3;j++){
			int num=b[j].num,id=b[j].id;
			if(tj[id]){
				tj[id]--;
				ans+=num;
				break;
			}
		}
		
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}