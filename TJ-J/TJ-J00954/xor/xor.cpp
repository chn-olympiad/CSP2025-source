#include<bits/stdc++.h>
using namespace std;
int a[500011];
int b[500011];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=b[j]^b[i-1];
			if(t==k){
				ans++;	
				i=j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
