#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int rc[m][2],wrd[m];
	int wcy[k],wcc[k][n];
	for(int i=0;i<m;i++){
		cin>>rc[i][0]>>rc[i][1]>>wrd[i];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>wcy[i]>>wcc[i][j];
		}
	}
	int cnt=0;
	
	if(k==0 && m==n-1){
		for(int i=0;i<m;i++){
			cnt+=wrd[i];
		} 
	}
	cout<<cnt;
	
	return 0;
}

