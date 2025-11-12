//强立琨 SN-S00270 交大附中浐灞右岸学校
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
};
vector<node> a[10010]; 
int b[10010],c[10010];
int n,m,k,mini,sma,big;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	} 
	for(int i=0;i<=n;i++){
		b[i]=1e9;
	}
	b[1]=0;
	for(int i=1;i<=n;i++){
		sma=1e9;
		for(int j=1;j<=n;j++){
			if(b[j]<sma && c[j]==0){
				mini=j;
				sma=b[j];
			}
		}
		c[mini]=1;
		for(int j=0;j<a[mini].size();j++){
			int u=a[mini][j].a;
			if(b[u]==1e9){
				b[u]=b[mini]+a[mini][j].b;
				big+=a[mini][j].b;
			}
			else if(b[u]>b[mini]+a[mini][j].b){
				big-=b[u];
				b[u]=b[mini]+a[mini][j].b;
				big+=b[u]-b[mini];
			}
		}
	}
	cout<<big;
	return 0;
} 
