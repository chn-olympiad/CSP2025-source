#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
bool check(int l,int r){
	int sum=0,mx=-1;
	for(int i=l;i<=r;i++){
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	return sum>2*mx;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(check(i,j)){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
