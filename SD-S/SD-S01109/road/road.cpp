#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int from,to,val,jia;
	bool operator < (const Edge &n)const{
		return val==n.val ? jia>n.jia : val>n.val;
	}
};
priority_queue<Edge> e;
int n,m,k,vv[20],node,f[10005],ans;
bool nodee[5000006];
int fa(int x){
	if(f[x]!=x) return f[x]=fa(f[x]);
	else return x;
}																	//who can tell me how to write bingchaji....
int bing(int x,int y){												//hao xiang xie dui le awa 
	return f[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e.push({x,y,z,0});
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		vv[i]=x;
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			e.push({i,j,y,x});
			nodee[node]=1;
		}
	}
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	while(!e.empty()){
		Edge wh=e.top();
		int x=wh.from,y=wh.to,val=wh.val,jia=wh.jia; 
		if(fa(x)!=fa(y)){
			bing(x,y);
			ans+=val;
			if(jia!=0&&vv[x]==1) {
				ans+=vv[x];
				vv[x]=0;
			}
		}
		e.pop();
	}
	cout<<ans;
	return 0; //wo kao le hai sheng ban ge xiao shi fa xian du cha ti le    qwq
}   
