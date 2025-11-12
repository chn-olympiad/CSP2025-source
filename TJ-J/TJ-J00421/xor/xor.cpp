#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000001],sum[1000001];
int pe=-1;
map<int,int>mp;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		int nd=sum[i]^k;
		if(mp.count(nd)){
			if(mp[nd]>=pe){
				ans++;
				pe=i;
			}
		}
		mp[sum[i]]=i;
	}
	cout<<ans;
} 
