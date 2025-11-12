#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0,ans=0,maxx=-1;
	for(int i=0;i<n;i++){
		cnt=a[i],maxx=-1;
		for(int j=i;j<n;j++){
			cnt+=a[j];
			maxx=max(maxx,a[j]);
			if(cnt>2*maxx and j-i+1>=3){
				ans++;
				ans%=998244353;
			} 
		}	
	}
	cout<<ans;
	return 0;
} 
