#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+27;

int n,k,ans=0;
long long a[MAXN];

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	// l-r sum[l-1]^sum[r]
	int las=0;
	long long s=0;
	
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j>las;j--){
			s^=a[j];
			if(s==k){
				ans++;
				las=i;
				break;
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}