#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c,sum=0;
	for(int i=1;i<=m;i++){
		cin>>b>>c;
		cin>>a;
		sum+=a;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
