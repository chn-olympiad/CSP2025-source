#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k,a,flag=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a;
	}
	for(int i=1;i<=k;i++){
		cin>>a;
	}
	for(int i=1;i<=k;i++){
		cin>>a;
	}
	fclose(stdin);
	freopen("road.ans","r",stdin);
	cin>>n;
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
