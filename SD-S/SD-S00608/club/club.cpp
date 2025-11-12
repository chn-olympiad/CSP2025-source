#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m;
	cin>>m;
	int manyi[m]{0};
	for(int q=0;q<m;q++){
		int n;
		cin>>n;
		int a[n][4];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(j==0){
					a[i][3]=a[i][j];
				}
				else if(a[i][j]>=a[i][3]){
					a[i][3]=a[i][j];
				}
				else {
					continue;
				}
			}
		}
		for(int i=0;i<n;i++){
			manyi[q]+=a[i][3];
		}
	}
	for(int i=0;i<m;i++){
		cout<<manyi[i]<<endl;
	}
	return 0;
}
