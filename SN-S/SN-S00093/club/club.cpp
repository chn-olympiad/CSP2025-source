//卜睿琛  SN-S00093  西安湖滨中学
#include<bits/stdc++.h>
using namespace std;
int n,m,a[10004][10004];
int sum=0,nut=0,egg=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(n%2==0){
				sum++;
				nut++;
				egg++;
			}
		}
	}
	cout<<sum<<endl;
	cout<<nut<<endl;
	cout<<egg;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

