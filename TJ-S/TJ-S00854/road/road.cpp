#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[100001];
	for(int i=1;i<=m+k;i++){
		cin>>a[i];
	}
	cout<<n+m+k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
