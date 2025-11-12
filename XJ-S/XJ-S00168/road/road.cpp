#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000010][5],b[20][10010],c[1000010][1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	int d=0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=m;i++){
			 if(a[i][1]==j||a[i][2]==j){
				c[j][1]=a[i][1];
				c[j][2]=a[i][2];
				c[j][3]=a[i][3];
			 }
		}
		for(int i=1;i<=k;i++){
			c[j][1]=j;
			c[j][2]=i+m;
			c[j][3]=b[i][j+1];
		}
		int o=INT_MAX;
		for(int i=1;i<=k+m;i++){
			
			o=min(o,c[i][3]);
			
	//		cout<<c[i][1]<<" "<<c[i][2]<<" "<<c[i][3]<<endl;
		}
		d+=o;
		
	}
	
	cout<<d;
	return 0;
}   
