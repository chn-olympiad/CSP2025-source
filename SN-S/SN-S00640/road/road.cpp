//Ñ¦ŞÈÆ½   ¸¨ÂÖÖĞÑ§   SN-S00640 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	long long a[100000008];
	for (int i=1; i<=n+1; i++){
		cin>>a[i];
	}
	cin>>u>>v>>w;
	int sum=0;
	int minn=1e9;
	int j;
	for (int i=1; i<=n; i++){
		sum+=(i*w);
		sum+=(k*i);
		sum+=(i*a[j]);
		min(sum,minn);
		if (minn>sum){
			minn=sum;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
