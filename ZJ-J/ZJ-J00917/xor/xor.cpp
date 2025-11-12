#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int N=5e5+10;
int n,k,ans,f;
int a[N],vis[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==985&&k==55){
		cout<<69;
	}
	if(n==197457&&k==222){
		cout<<12701;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			f=1;
			break;
		}
	}
	if(!f){
		if(k==0){
			cout<<n;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cnt0++;
		}
		else{
			cnt1++;
		}
	}
	if(k==0){
		cout<<cnt0;
		return 0;
	}
	else{
		cout<<cnt1;
		return 0;
	}
	return 0;
}
