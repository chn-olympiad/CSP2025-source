#include<bits/stdc++.h>
using namespace std;
long long a[1001][1001]={0};
long long c[11][1001]={1e12};

int n,m,k;
long long di(int i,int j){
	if(a[i][j]!=0){
		return a[i][j];
	}
	long long minn=1e12;
	for(int k=1;k<=n;k++){
		if(a[k][j]!=0){
			minn=min(minn,a[k][j]+di(i,k));
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	long long ans=0;
	cin >> n >>m >>k;
	for(i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	}
	for(i=0;i<k;i++){
		cin >> c[i][0];
		for(j=1;j<=n;j++){
			cin >> c[i][j];
		}
	}
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			a[i][j]=di(i,j);
			cout << i << " " << j << " " << a[i][j];
			for(int q=0;q<k;q++){
				
				long long c1=c[q][0]+c[q][i]+c[q][j];
				a[i][j]=min(a[i][j],c1);	
			} 
			ans+=a[i][j];
		}
	}
	cout << ans;
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
