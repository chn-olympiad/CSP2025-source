#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+10;
int n,k,a[N],sum[N],f[N];
map<int,int> last;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			f[i]=f[i-1]+1;
		}
		else if(last[(k^sum[i+1])]>0){
			f[i]=max(f[i-1],f[last[(k^sum[i+1])]-1]+1);
		}else{
			f[i]=f[i-1];
		}
		last[sum[i]]=i;
	}
	cout<<f[n];
	
	return 0;
} 
