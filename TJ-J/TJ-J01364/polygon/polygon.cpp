#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,ans=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]!=1) ans=0;
	}
	if(ans==-1){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int maxx=-1,sum=0;
			for(int k=i;k<=j;k++){
				maxx=max(maxx,a[k]);
				sum+=a[k];
			}
			if(maxx*2<sum) ans++;
		}
	}
	cout<<ans;
	//I am AK CSP-J
	return 0;
}

