#include <bits/stdc++.h>
#define i64 long long
using namespace std;

const int N = 5e5+10;

int n,k;
int a[N],s[N],f[N],r;
map<int,int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}for(int i=1;i<=n;i++){
		int t=mp[s[i]];
		f[i]=f[i-1];
		if(a[i]==k){
			f[i]++,r=i;
			continue;
		}if(t){
			if(t>r) f[i]=max(f[i],f[t-1]+1),r=i;
		}mp[s[i-1]^k]=i;
	}
	cout<<f[n]<<endl;
	return 0;
}