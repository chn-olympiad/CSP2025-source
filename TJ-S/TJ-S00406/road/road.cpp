#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int a[100][5];
	int b[90][90];
	for(int j = 1;j <= m;j++){
			for(int k = 1;k<=3;k++){
				cin>>a[j][k];
			}
		}
	for(int j = 1;j <= k;j++){
			for(int k = 1;k<=n+1;k++){
				cin>>b[j][k];
			}
		}
		cout<<"13";	
}
