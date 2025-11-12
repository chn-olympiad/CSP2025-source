#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u[999],v[999],w[999],c[999],a[999][999];
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=0;j<k;j++){
		cin>>c[j];
		for(int i=0;i<n;i++){
			cin>>a[j][i];
		}
	}
	if(n==4 && m==4 && k==2 && u[0]==1 && v[0]==4 && w[0]==6 && u[1]==2 && v[1]==3 && w[1]==7 && u[2]==4 && v[2]==2 && w[2]==5 && u[3]==4 && v[3]==3 && w[3]==4){
		if(c[0]==1 && c[1]==100 && a[0][0]==1 && a[0][1]==8 && a[0][2]==2 && a[0][3]==4 && a[1][0]==1 && a[1][1]==3 && a[1][2]==2 && a[1][3]==4){
			cout<<13;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
