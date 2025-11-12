#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5005];
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=(1<<n)-1;i++){
		int m=0,sum=0,mx=0;
		for(int j=0;j<n;j++){
			if((i&(1<<j))!=0){
				sum+=a[j+1];
				mx=max(mx,a[j+1]);
				m++;
				//cout<<j<<" ";
			}
		}
		if(m>=3&&sum>mx*2) ans++; 
	}
	cout<<ans;
	return 0;
}

