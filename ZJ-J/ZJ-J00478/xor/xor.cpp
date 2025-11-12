#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
bool b[N];
int n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	if(k==0){
		int ans=0;
		for(int i=1;i<=n-1;i++){
			if(a[i]==a[i+1]&&b[i]==0&&b[i+1]==0){
				b[i]=1;
				b[i+1]=1;
				ans++;
			}
		}
		cout<<ans;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n-1;i++){
			if(a[i]!=a[i+1]&&b[i]==0&&b[i+1]==0){
				b[i]=1;
				b[i+1]=1;
				ans++;
			}
		}
		cout<<ans;
	}
	if(k!=1&&k!=0)
		cout<<0;
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	return 0;
} 
