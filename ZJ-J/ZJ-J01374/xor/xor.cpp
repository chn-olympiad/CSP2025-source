#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[1005][1005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>1000){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int f=a[i];
		b[i][i]=f;
		for(int j=i+1;j<=n;j++){
			f=f^a[j];
			b[i][j]=f;
		}
	}
	int it=n+1;
	for(int i=n;i>=1;i--){
		for(int j=i;j<it;j++){
			if(b[i][j]==k){
				ans++;
				it=i;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}