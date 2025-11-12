//卜睿琛  SN-S00093  西安湖滨中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,sum=0;
	long long a[1000006][1000006];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>k;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum+=k;
		}
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
