#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
int f[500005];
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	int la=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=(a[i]^f[i-1]);
		int x=mp[(f[i]^k)];
		if((f[i]==k&&la==0)||(x!=0&&x>=la)){
			cnt++;
			la=i;
		}
		mp[f[i]]=i;
	}
	cout<<cnt;
	return 0;
}
//sto Tcer orz
