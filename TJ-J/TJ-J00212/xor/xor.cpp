#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[5000010];
int b[5000010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int j=1;j<=n;j++){
		cin>>a[j];
		b[j]=b[j-1]^a[j];
	}
	int t=1,ans=0;
	while(t<=n){
		int e=n;
//		cout<<t<<endl;
		int f=0;
		for(int j=t;j<=e;j++){
			for(int l=j;l<=n;l++){
				if((b[l]^b[j-1])==k){
//					cout<<l<<"&"<<j<<"&"<<(b[l]^b[j-1])<<" ";
					e=min(e,l);
					f=1;
				}
			}
		}
//		cout<<endl;
		t=e+1;
		if(f) ans++;
	}
	cout<<ans;
	return 0;
}
