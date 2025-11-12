#include <bits/stdc++.h>
#define int long long
using namespace std;
const int NB1=1e6+5,NB2=1e4+5;
int n,m,k,ans=0,fa[NB2],cost[13],cons[13][NB2];
bool vis1[13],vis2[13][NB2];
struct node
{
	int uu,vv,weight;
} a[NB1];
bool cmp(node sheng,node ge)
{
	return sheng.weight<ge.weight;
}
int find(int tarx)
{
	if(fa[tarx]==tarx) return tarx;
	else return find(fa[tarx]);
}
void united(int tarx,int tary)
{
	tarx=find(tarx);
	tary=find(tary);
	if(tarx<tary) swap(tarx,tary);
	if(tarx!=tary) fa[tary]=tarx;
	return ;
}
signed main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].uu>>a[i].vv>>a[i].weight;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++) {
		cin>>cost[i];
		for(int j=1;j<=n;j++) cin>>cons[i][j];
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int rres=a[i].weight,mind=1e18,posc=0,rpos=find(a[i].vv);
		if(find(a[i].uu)==find(a[i].vv)) continue;
		for(int ll=1;ll<=n;ll++) {
			if(find(ll)!=rpos) continue;
			for(int j=1;j<=k;j++) {
				int conres=0;
				if(!vis2[j][a[i].uu]) conres+=cons[j][a[i].uu];
				if(!vis2[j][ll]) conres+=cons[j][ll];
				if(!vis1[j]) conres+=cost[j];
				if(conres<mind) posc=j;
				mind=min(mind,conres);
			}
		}
		ans+=min(rres,mind);
		united(a[i].uu,a[i].vv);
		if(mind<=rres) {
			vis2[posc][a[i].uu]=true;
			vis2[posc][a[i].vv]=true;
			vis1[posc]=true;
		}
	}
	cout<<ans;
	return 0;
}
