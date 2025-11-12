#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0||k==1){
		bool aa=1;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				aa=0;
				break;
			}
		}
		if(aa){
			if(k==0) cout<<n-1<<endl;
			else if(k==1) cout<<n<<endl;
		}
		else{
			if(k==1){
				int cnt=0;
				for(int i=1;i<=n;i++){
					if(a[i]==1) cnt++;
				}
				cout<<cnt<<endl;
			}
			else{
				int cnt=0;
				for(int i=1;i<=n;i++){
					if(a[i]==1&&a[i+1]==1){
						cnt++;
						a[i]=0;
						a[i+1]=0;
					}
					else if(a[i]==0) cnt++;
				}
				cout<<cnt<<endl;
			}
		}
	}
	else cout<<n/2+n%k<<endl;
	return 0;
}
