#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
int s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,k,x,e=0;cin>>n>>k;
	if(k==1){cout<<n;return 0;}
	for(int i=1;i<=n;i++){
		cin>>x;
		s[i]=s[i-1]^x;
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				m.insert({i,j});
				break;}
		}
	}long long c=0;
	for(auto i:m){
		if(i.first>e) e=i.second,c++;
	}cout<<c;
	return 0;
}
