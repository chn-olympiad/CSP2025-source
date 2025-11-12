#include<bits/stdc++.h>
using namespace std;
int n,m,arr[15][15],r,px[1005];
int main(){
	 freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>px[i];
	}
	r = px[1];
	sort(px+1,px+n*m+1);
	for(int i = 1;i<=(n*m)/2;i++){
		int ts = px[i];
		px[i]=px[n*m-i+1];
		px[n*m-i+1] = ts;
		
	}
	int sum = 1;
	for(int i =1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			if(px[sum]==r){
				cout<<i<<" "<<j;                        
			}
			arr[i][j]=px[sum];
			sum++;
		}
	}

	return 0;
}

