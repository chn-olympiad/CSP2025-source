#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long pre[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	cout<<(3^1);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
//	for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
	//cout<<(pre[4]^pre[1]);
//	cout<<endl;
	//a[l]^a[l+1]...^a[r]=pre[r]^pre[l-1]
	int ans=0;
	int j=1;
	for(int i=1;i<=n;i++){
		//cout<<1;
		bool flag=false;
		int xj=j;
		for(;j<=i;j++){
			//cout<<i<<" "<<j<<endl;
			long long x=pre[i]^pre[j-1];
			if(x==k){
				//cout<<(pre[i]^pre[j-1])<<" "<<k<<endl;
				ans++;
				
				/*cout<<x<<" ";
				cout<<i<<" "<<j<<endl;*/
				j=i+1;
				flag=true;
				break;
			}
		}
		if(!flag) j=xj;
	}
	
	cout<<ans;
	return 0;
}
