#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long lj[1001][1001]={};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		lj[a][b]=c;
		lj[b][a]=c;
	}
	for (long long i=1;i<=k;i++){
		long long a[n+1],f=0,x;
		cin>>x;
		for (int j=1;j<=n;j++){
			cin>>a[i];
			if(a[i]==0){
				f=i;
			}
		}
		for (int j=1;j<=n;j++){
			if (lj[j][f]){
				lj[j][f]=min(lj[j][f],a[j]);
				lj[f][j]=lj[j][f];
			}
		}
	}
	long long s=0;
	for (int i=2;i<=n;i++){
		long long fl=0,minn=2147483645;
		if (lj[1][i]) fl++;
		for (int j=1;j<=n;j++){
			if (lj[1][j]&&lj[j][i]){
				if(fl){
					minn=min(minn,min(lj[1][i],lj[1][j]+lj[j][i]));
				}else{
					minn=min(minn,lj[1][j]+lj[j][i]);
				}
			}
		}
		lj[1][i]=minn;
		lj[i][1]=lj[1][i];
		s+=minn;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
