#include <bits/stdc++.h>
using namespace std;
long long a[10][100015][5],maxx=-10,sum=0,n[10],flag[10][100015];
bool chk[10][100015][5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[i][j][1]>>a[i][j][2]>>a[i][j][3];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n[i];j++){
			for(int z=1;z<=3;z++){
				if(a[i][j][z]>maxx) maxx=a[i][j][z];
			}
			sum=sum+maxx;
			maxx=-10;+
		}
		cout<<sum<<endl;
		sum=0;
	}
	
	return 0;
}