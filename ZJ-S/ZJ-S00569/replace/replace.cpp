#include<bits/stdc++.h>
constexpr int N=2e5+2;
typedef long long ll;
int n,q,ans;
std::string a[N],b[N],x,y;
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	std::cin>>n>>q;
	for(int i=1;i<=n;i++){
		std::cin>>a[i]>>b[i];
	}
	while(q--){
		int ans=0;
		std::cin>>x>>y;
		if(x.size()!=y.size()){
			std::cout<<"0\n";continue;
		}
		for(int i=1;i<=n;i++){
			int l=a[i].size(),l2=x.size();
			for(int j=0;j<l2-l+1;j++){
				if(x.substr(j,l)==a[i] and y.substr(j,l)==b[i] and (j==0 or x.substr(0,j)==y.substr(0,j)) \
				and (j+l==l2 or x.substr(j+l)==y.substr(j+l))){
					ans++;
				}
			}
		}
		std::cout<<ans<<'\n';
	}
}
