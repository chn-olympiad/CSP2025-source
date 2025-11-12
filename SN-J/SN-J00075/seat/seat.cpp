#include <bits/stdc++.h>
using namespace std;
int n,m,ans[21][21],a,seat[801],num=0;
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a=n*m;
	for(int i=1;i<=a;i++){
		cin>>seat[i];
	}
	r=seat[1];
	sort(seat+1,seat+1+a);
	for(int i=n;i>=1;i--){
		if(i%2==0){
			for(int j=1;j<=m;j++){
				num++;
				ans[i][j]=seat[num];
				if(seat[num]==r){
				cout<<i<<" "<<j;
				}
			}
			continue;
		}
		for(int j=m;j>=1;j--){
			num++;
			ans[i][j]=seat[num];
			if(seat[num]==r){
				cout<<i<<" "<<j;
			}
		}
	}
	
	return 0;
}

