#include<bits/stdc++.h>
using namespace std;
long long mx=9e18,b[1010][1010],n,m,f[10010],p,k,x,y,z,ans,jilu[10010];
struct node{
	long long u,v,w;
}a[1000010];
bool cmp(node i,node j){
	return i.w<j.w;
}
long long find(long long q){
	if(f[q]==q)return q;
	return f[q]=find(f[q]);
}
int main(){
	//测试点1~4 + 大部分特殊性质A
	//目标42分 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	if(k==0){
		while(m--){
			cin>>a[p].u>>a[p].v>>a[p].w;
			p++;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=mx;
			}
		}
		
		while(m--){
			cin>>x>>y>>z;
			b[x][y]=min(b[x][y],z);
			b[y][x]=min(b[y][x],z);
		}
		
		for(int i=1;i<=k;i++){
			cin>>x;
			for(int j=1;j<=n;j++){
				cin>>jilu[j];
				for(int q=1;q<j;q++){
					b[j][q]=min(b[j][q],jilu[q]+jilu[j]);
					b[q][j]=min(b[q][j],jilu[q]+jilu[j]);
				}	
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[p].u=i,a[p].v=j,a[p++].w=b[i][j];
				//cout<<b[i][j]<<"\n";
			}
		}
	}
		sort(a,a+p,cmp);
	
		for(int i=0;i<p;i++){
			//cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<'\n';
			x=find(a[i].u),y=find(a[i].v);
			if(x==y)continue;
			f[x]=y;
			ans+=a[i].w;
		}
		cout<<ans;
        return 0;
}