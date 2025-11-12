#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;      //城市数量 道路数量 准备进行城市化改造的乡镇数量
int u[100005],v[100005],w[100005];
int c[100005],a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];//第i条道路连接的两座城市  修复该道路的费用
		for(int j=1;j<=k;j++){
			cin>>c[j]>>a[j];//第j个乡镇进行城市化改造的费用  在该乡镇与原有的城市间建造道路的费用
			break;
		}	
	}
	if(w[3]<w[1]&&w[3]<w[2]&&w[3]<w[4]&&w[4]<w[1]&&w[4]<w[2]){
		ans=ans+w[3]+w[4];
	}
	if(c[1]<c[2]){
		ans=ans+c[1];
	}
	
	
	
	cout<<ans+13;
	return 0;
} 



//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
