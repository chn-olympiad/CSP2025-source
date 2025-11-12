#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[100001],v[100001],w[100001];
long long c[20][11111];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;//分别表示原有的城市数量、道路数量和准备进行城市化改造的乡镇数量
	for(long long i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(long long i=0;i<=k;i++){
		for(long long j=0;j<=n;j++)cin>>c[i][j];//表示将第 j 个乡镇进行
		//                                          城市化改造的费用与在该
		//                                          乡镇与原有的城市间建造道路的费用
	}
	cout<<"。"; 
	return 0;
}

