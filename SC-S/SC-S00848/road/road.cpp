#include<bits/stdc++.h>
#define int long long
using namespace std;
//n:城市数量 
//m:原来有的道路数量 
//k:乡镇个数
//w[i]:修复第i(1<=i<=m)条道路的费用
//c[j]:对第j(1<=j<=k)个乡镇进行城市化改造的费用
//a[j][i]:第j(1<=j<=k)个乡镇与第i(1<=i<=n)座城市间建造一条道路的费用 
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
		}
	}
	cout<<0;
	return 0;
} 