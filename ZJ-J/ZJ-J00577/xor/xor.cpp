#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,tot;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		bool flag=0;
		cin>>x;
		int v=x;
		if(v==k){
			ans++;
			tot=0;
			continue;
		}
		for(int j=tot;j>=1;j--){
			v^=a[j];
			if(v==k){
				ans++;
				tot=0;
				flag=1;
				break;
			}
		}
		if(!flag)a[++tot]=x;
	}
	cout<<ans;
	return 0;
}
