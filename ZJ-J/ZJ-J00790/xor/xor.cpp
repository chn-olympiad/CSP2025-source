#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans=0;
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	int p=0,now=0;
	for(int i=1;i<=n;i++){
		now=a[i]^a[p];
		if(now==k||mp[k^now]>p){
			ans++;
			p=i;
		}
		else{
			mp[now]=i;
		}
	}
	cout<<ans;
	return 0;
}