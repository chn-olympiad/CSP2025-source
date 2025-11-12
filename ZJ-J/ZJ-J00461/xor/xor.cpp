#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,k,a[maxn],ans,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		long long res=0;
		for(int j=i;j>cnt;j--){
			res^=a[j];
			if(res==k){
				cnt=i;
				ans++;
				break;
			}	
		}
	}
	cout<<ans;
	return 0;
}