#include<bits/stdc++.h>
using namespace std;
vector<int> a[100000];//建立图 
struct node{
	int x;
	int y;
	int val;
}v[10000];//记录每一条边 
int c[10000][10000];
int tim[100000];//记录每个点的出度和入度之和 
bool cmp(node l,node r){
	return l.val>r.val;
}
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++){
		int x,z,w;
		cin>>x>>z>>w;
		ans+=w;
		a[x].push_back(z);
		a[z].push_back(x);
		tim[x]++;
		tim[z]++;
		v[i].val=w;
		v[i].x=x;
		v[i].y=z;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)//c[i][0]表示此乡镇建设需要的花费 
		cin>>c[i][j];
	}
	if(k==0){
		sort(v+1,v+1+m,cmp);
		int f=1;
		int k=1;
		for(int i=1;i<=m;i++){
			if(tim[v[k].x]>=2&&tim[v[k].y]>=2){
				tim[v[k].x]--;
				tim[v[k].y]--;
				ans-=v[k].val;
				f=0;
			}else f=1;
			k++;
		}
		if(f==1){
			cout<<ans;
		}
	}
}
