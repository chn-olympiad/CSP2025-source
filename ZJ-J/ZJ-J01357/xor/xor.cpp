#include<bits/stdc++.h>
using namespace std;
int n,k,A[600010],lend=0,ans=0;
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		A[i]^=A[i-1];
		int dd=mp[A[i]^k];
		if(dd!=0){
			if(lend<dd){
				ans++,lend=i;
			}
		}
		mp[A[i]]=i+1;
	}
	cout<<ans;
	return 0;
}
