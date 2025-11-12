#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a[m][3],b[k][n+1],d[m+1],sum=0;;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		} 
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>b[i][j];
		} 
	}
	if(k==0){
		for(int i=0;i<m;i++){
			d[i+1]=a[i][2];
		} 
		sort(d,d+m);
		for(int i=0;i<n-1;i++){
			sum+=d[i];
		}
		cout<<sum;
	}
	else cout<<"0";
	return 0;
}

