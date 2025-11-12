#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],rxm,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=1;
	cin>>rxm;a[1]=rxm;//little ming's record
	for (int i=2;i<=n*m;++i){
		cin>>a[i];
		if (a[i]>rxm){
			sum++;
		}
	}
	for (int i=1;i<=m;++i){//lie
		if (i%2==1){//zheng
			for (int j=1;j<=n;++j){//hang
			//************************
			//cout<<i<<" "<<j<<"\n";
			//*************************
				sum--;
				if (sum==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else {//fan
			for (int j=n;j>=1;--j){//hang
			//************************
			//cout<<i<<" "<<j<<"\n";
			//*************************
				sum--;
				if (sum==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
