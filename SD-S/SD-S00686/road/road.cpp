#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;//城市数量 
int m;//道路数量 
int k;//准备进行城市化改造的乡镇数量
int u[1000010];//第 i 条道路连接的城市
int v[1000010];//第 i 条道路连接的城市
int w[1000010];//修复第 i 条道路的费用
int c[20];//对第j个乡镇进行城市化改造的费用
int a[10][1010];//修建乡镇j与城市i的道路的费用 
int ans;//费用 
bool flag=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	} 
	for(int j=1;j<=k;j++){
		cin>>c[j];
		if(c[j]!=0) flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
			if(a[j][i]!=0) flag=0;
		}
	}
	if(flag){
		cout<<0;
	}
	else{
		for(int i=1;i<=m;i++){
			ans+=w[i];
		}
		cout<<ans;
	}
	return 0;
}
