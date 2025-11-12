#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,num=0;
	cin>>n>>m>>k;
	int u1,u2,u3;
	for(int i=1;i<=m;i++){
		cin>>u1>>u2>>u3;
		num+=u1+u2+u3;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		num+=a[i];
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
