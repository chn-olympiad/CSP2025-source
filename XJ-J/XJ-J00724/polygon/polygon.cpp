#include<bits/stdc++.h>
using namespace std;
int n,a[305],sum,zd=INT_MIN,cnt,vis[10086];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(zd<a[i]){
			zd=a[i];
		}
	}
	if(zd*2<sum){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
