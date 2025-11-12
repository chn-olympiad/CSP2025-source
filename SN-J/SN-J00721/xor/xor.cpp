//SN-J00721  Õı •ø≠ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+2;
int n,k,a[N],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int x=0;
	for(int i=1;i<=n;i++){
		int now=0;
		for(int j=i;j>x;j--){
			now^=a[j];
			if(now==k){
				ans++;
				x=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

