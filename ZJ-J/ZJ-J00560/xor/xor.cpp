#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int n,k;
int f[N];
unordered_map<int,int>mp;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    mp[0]=0;
    int s=0;
    for(int i=1;i<=n;i++){
    	int x;cin>>x;
    	s^=x;
    	f[i]=f[i-1];
    	if(mp.count(k^s))f[i]=max(f[i],mp[k^s]+1);
    	mp[s]=f[i];
	}
	cout<<*max_element(f+1,f+n+1);
}