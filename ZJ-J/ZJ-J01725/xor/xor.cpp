#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,k,a[maxn],s[maxn],st=1,ans,c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
	while(st<=n){
		int d=1;
		for(int i=1;i<=n-st+1;i++){
			long long t=s[st+i-1]^s[st-1];
			if(t==k){ans++,d=i;break;}
		}
		st+=d;
	}
	cout<<ans;
	return 0;
}
/*
By ZJ-J01725.
Luogu UID:1086453.
*/
