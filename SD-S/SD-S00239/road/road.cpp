#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0,sum=0,ans1=0,sum1=0,sum2=0;//城市，道路，新城市，总价值 
long long a[10010][10010],c,x,y;//地图 ,道路价值，起始点，终止点 
long long b[15][10010],d[10010];//新城市道路 
bool t=1;//特殊性质A 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>x>>y>>c;
		if(a[min(x,y)][max(x,y)]!=0){
			a[min(x,y)][max(x,y)]=min(a[min(x,y)][max(x,y)],c);
		}else{
			a[min(x,y)][max(x,y)]=c;
		}
	}
	for(long long i=1;i<=k;i++){
		cin>>d[i];
		for(long long j=1;j<=n;j++){
			cin>>b[i][j];
			if(b[i][j]+c!=0){
				t=0;
			}
		}
	}
	if(t){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=k;i++){
		for(long long j=1;j<=n;j++){
			for(long long p=j+1;p<=n;p++){
				if(a[j][p]!=0){
					a[j][p]=min(a[j][p],b[i][j]+b[i][p]+d[i]);
				}else{
					a[i][p]=b[i][j]+b[i][p]+d[i];
				}
			}
		}
	}
	
	for(long long i=1;i<=n;i++){
		sum=0;
		sum1=0;
		for(long long j=i+1;j<=n;j++){
			if(sum!=0){
				sum=min(sum,a[i][j]);
			}else{
				sum=a[i][j];
			}
		}
		ans1+=sum;
	}
	for(long long j=2;j<=n;j++){
		sum=0;
		sum1=0;
		for(long long i=1;i<j;i++){
			if(sum!=0){
				sum=min(sum,a[i][j]);
			}else{
				sum=a[i][j];
			}
		}
		ans+=sum;
	}
	cout<<min(ans,ans1); 
	return 0;
} 
