#include <bits/stdc++.h>
#define int long long
const int MAXN=5005;
std::map<std::pair<std::string,std::string>,int> mp; 
int n,q;
std::string s1[MAXN],s2[MAXN];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	std::cin>>n>>q;
	for(int i=1;i<=n;i++){
		std::cin>>s1[i]>>s2[i];
		mp[{s1[i],s2[i]}]=1;
		//std::cout<<s1[i]<<' '<<s2[i]<<'\n';
	}
	while(q--){
		std::string t1,t2;
		std::cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			std::cout<<0<<'\n';
			continue;
		}int tot=0;
		for(int i=0;i<t1.size();i++){
			for(int j=i;j<t1.size();j++){
				//std::string tt1=t1;

				std::string tt1;
				for(int k=i;k<=j;k++)tt1.push_back(t1[k]);
				std::string tt2;
				for(int k=i;k<=j;k++)tt2.push_back(t2[k]);
			//	std::cout<<tt1<<' '<<tt2<<'\n';
				int flg=1;
				for(int k=0;k<i;k++){
					if(t1[k]!=t2[k])flg=0;
				}
				for(int k=j+1;k<t1.size();k++){
					if(t1[k]!=t2[k])flg=0;
				}
				if(mp[{tt1,tt2}]>=1&&flg){
					tot++;
				}
			}
		}std::cout<<tot<<'\n';
	}
	return 0;
}
//L1 log L1+q*(l2/q)*(l2/q) log L2/q
//csps rp++!
//scanf 用lld!
//算算空间时间!
//Ren5Jie4Di4Ling5%

