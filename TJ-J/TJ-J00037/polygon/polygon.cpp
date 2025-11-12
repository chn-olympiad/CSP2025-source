#include <bits/stdc++.h>
using namespace std;

int n,r[5010],ans=0,sum,ma;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		ma+=r[i];
		for(int i=1;i<=n-1;i++){
			sum+=r[i];
		}
		if(sum>r[n] && ma>2*r[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}