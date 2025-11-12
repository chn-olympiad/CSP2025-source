//SN-J00620 杨昕然 西安高新第一中学  
#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],mp[1048590],ans[500005],Maxans[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1; i<=n; i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
		if(mp[s[i]^k]||((s[i]^k)==0))ans[i]=Maxans[mp[s[i]^k]]+1;
		Maxans[i]=max(ans[i],Maxans[i-1]);
		mp[s[i]]=i;
	}
	cout<<Maxans[n];
	return 0;
}
/*
a^b=k;
a^k=b
*/
/*
1.
4 1
0 0 0 0
ans:0

2.
4 1
0 1 0 0
ans:1

longlong

1.前缀和 
*/
