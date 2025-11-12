#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[100001],d[100001],a,e[100001],f[20][100001],js=1,zhf,mi[100000],dl[100001][100001],hf[100],hf2,hf1,ma=1000000000;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>c[i]>>d[i]>>e[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		hf1=0;
		for(int j=1;j<=m;j++){
			if(e[j]>f[i][c[i]+1]+f[i][d[i]+1]){
				hf[i]=hf[i]+f[i][c[i]+1]+f[i][d[i]+1];
				f[i][c[i]+1]=0;
				f[i][d[i]+1]=0;
				hf1=hf1+e[j]-f[i][c[i]+1]+f[i][d[i]+1];
				hf2=e[j]+hf2;
				e[j]=0;
			}
			if(j==m){
				if(hf1+f[i][1]<hf2){
					hf2=0;
				}
			}
		}
		if(hf2==0){
			for(int j=1;j<=k;j++){
				if(hf[j]+f[i][1]<ma){
					ma=hf[j];
					a=j;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		zhf=zhf+e[i];
	}
	zhf=zhf+ma;
	zhf=zhf+f[a][1];
	cout<<zhf;
	return 0;
}