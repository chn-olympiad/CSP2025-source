#include <bits/stdc++.h>
using namespace std;
int n,ans,a[5010];
int C(int x,int y){
	int t=1;
	for(int i=x;i>=x-y+1;i--){
		t*=i;
	}
	for(int i=y;i>=1;i--){
		t/=i;
	}
	return t;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		ans+=C(n,i);
	}
	cout<<ans<<endl;
	return 0;
} 
