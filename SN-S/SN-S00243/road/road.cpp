#include<bits/stdc++.h>

using namespace std;

long long n,m,k,u1,u2,w1,c1,a1[1005]={},x=0,y=0,ans=1e8,jilu=0,ans2=0;
long long a[1005][1005]={}; 
bool pd[1005]={};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u1>>u2>>w1;
		a[min(u1,u2)][max(u1,u2)]=w1+1;
	}
	for(int i=1;i<=k;i++){
		cin>>c1;
		for(int j=1;j<=n;j++){
			cin>>a1[j];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i][j]){
					a[i][j]=min(a[i][j],c1+a1[i]+a1[j]+1);
				}
				else{
					a[i][j]=c1+a1[i]+a1[j]+1;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]){
				a[i][j]=min(a[i][j],c1+a1[i]+a1[j]+1);
			}
			else{
				a[i][j]=c1+a1[i]+a1[j]+1;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]<=ans){
				ans=a[i][j];
				x=i;
				y=j;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]){
				a[i][j]-=1;
			}
		}
	}
//
	pd[x]=1;
	pd[y]=1;
	jilu=2;
	ans2+=a[x][y];
//	cout<<ans2<<endl;
	a[x][y]=1e8;
	while(jilu<n){
		ans=1e8;
		for(int i=1;i<=n;i++){
			if(pd[i]){
				for(int j=1;j<=n;j++){
					if((a[min(i,j)][max(i,j)]<ans)&&(i!=j)){
						ans=a[min(i,j)][max(i,j)];
						x=i;
						y=j;
					}
				}
			}
		}
		ans2+=a[x][y];
		cout<<ans2<<endl;
		pd[y]=1;
		jilu++;
		a[x][y]=1e8;
	}
	cout<<0;
	return 0;
}
