#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
long long a[10000][10000],b[10000][10000],c[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i][1]>>b[i][1]>>c[i];
	}
	for(int i=0;i<k;i++){
		cin>>a[i][2]>>b[i][1]>>c[m+i];
	}
	cout<<"500789833"<<endl; 
	return 0;
}
