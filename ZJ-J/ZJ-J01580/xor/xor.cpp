#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0,t;
long long a[500005];
long long b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=b[i-1]^a[i];
		b[i]=t;
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				long long t=b[j]^b[i-1];
//				cout<<t<<" ";
				if(t==k){
					ans++;
//					cout<<i<<" "<<j<<"\n";
					i=j;
					if(j!=n) i++;
				}
			}
		}
		cout<<ans;	
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
/*

*/
