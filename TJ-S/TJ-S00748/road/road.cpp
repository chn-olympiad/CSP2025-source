#include<bits/stdc++.h>

using namespace std;
long long ans=1,MAXN=998244353;
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	for(int i=1;i<=100;i++){
		ans=(ans*i)%MAXN;
		cout<<ans<<endl;
	}
	return 0;
}
