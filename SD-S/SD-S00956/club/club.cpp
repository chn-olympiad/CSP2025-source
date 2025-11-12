#include <bits/stdc++.h>
using namespace std;
int t=0,sum=0,r1=0,r2=0,r3=0;
int n=0,b,a[4][100005];
/*dfs(int ceng,int men,int zhi,int zd){
	//cout<<zhi<<' ';
	//cout<<zd<<endl;
	ceng++;
	cout<<ceng;
	if(r1>b){
		return 0;
	}else if(r2>b){
		return 0;
	}else if(r3>b){
		return 0;
	}
	if(ceng>=n){
		return zd;
	}
	cout<<r1<<' '<<r2<<' '<<r3<<endl;
	dfs(ceng,1,zhi,zd);r1++ or dfs(ceng,2,zhi,zd);r2++ or dfs(ceng,3,zhi,zd);r3++;
	
	
	
	cout<<endl<<endl<<endl;
	
	//zhi=zhi+a[men][ceng];
	if(zhi>zd){
		zd=zhi;
	}
	/*
	if(r1<=b){
		r1++;
		dfs(ceng,1,zhi,zd);
	}
	if(r2<=b){
		r2++;
		dfs(ceng,2,zhi,zd);
	}
	if(r3<=b){
		r3++;
		dfs(ceng,3,zhi,zd);
	}
	
	
}*/
int main() {
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		b=n/2;
		for(int i=0;i<=3;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			sum+=max(max(a[1][i],a[2][i]),a[3][i]);
		}
		cout<<sum<<endl;
		return 0;
	}
	return 0;
}
