#include<bits/stdc++.h>
const int N=2e5+5;
int n,m;
std::string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;++i) std::cin>>s1[i]>>s2[i];
	while(m--){
		std::string u,v;
		std::cin>>u>>v;
		int cnt=0;
		bool flag=0;
		for(int j=1;j<=u.size();++j){
			if(u[j]!=v[j] and !flag){
				cnt++;
				flag=1;
			}
			if(u[j]==v[j] and flag) flag=0;
		}
		if(cnt>=2 or cnt==0){
			puts("0");
			continue;
		}
		puts("0");
	}
	return 0;
}