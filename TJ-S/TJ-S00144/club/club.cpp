#include <bits/stdc++.h>
using namespace std;
int t,n,m[1001][3],w[1001];
int cl(int x,int l[1001][3]){
	int sum,v[3];
	for(int i=1;i<=x;i++){
		if(l[i][1]>=l[i][2]&&l[i][1]>=l[i][3]){
			sum+=l[i][1];
			v[1]++;
		}
		if(v[1]>n/2){
			break;
		}
	}
	for(int i=1;i<=x;i++){
		if(l[i][2]>=l[i][1]&&l[i][2]>=l[i][3]){
			sum+=l[i][2];
			v[2]++;
		}
		if(v[2]>n/2){
			break;
		}
	}
	for(int i=1;i<=x;i++){
		if(l[i][3]>=l[i][2]&&l[i][3]>=l[i][1]){
			sum+=l[i][3];
			v[3]++;
		}
		if(v[3]>n/2){
			break;
		}
	}
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
			cin>>m[i][j];
		}
			w[i]=cl(n,m);
	}
	for(int i=1;i<=t;i++){
		cout<<w[i]<<" ";
	}
	return 0;
}
