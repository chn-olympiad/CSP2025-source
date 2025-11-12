#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,ans,a[N][N],dis[N],from[N];
int e[M*2],v[M*2],ne[M*2],h[N],idx;
void add(int x,int y,int z){
	e[++idx]=y;
	v[idx]=z;
	ne[idx]=h[x];
	h[x]=idx;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){// 基本数据储存 
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z),add(y,x,z);
	}
	for(int i=1;i<=n;i++){
		for(int j=h[i];j;j=ne[j]){
			int to=e[i],val=v[i];
			if(dis[to]>dis[i]+val or dis[to]==0){
				ans-=dis[to];
				dis[to]=dis[i]+val;
				from[to]=i;
				ans+=dis[to];
			} 
		}
	}
	for(int i=1;i<=k;i++){// 基本数据储存 
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<ans;
	return 0;
}
/*

答题可能思路：

F1：思路分析：
	先根据先前给出的城市交通数据构建出最小生成树，得出不用城乡改造的最优答案；
	再通过枚举最小生成树上的边，看看是否能用两条改造边+一个改造点代替（知识盲区）； 
	
	期望得分：
	16pts 
*/