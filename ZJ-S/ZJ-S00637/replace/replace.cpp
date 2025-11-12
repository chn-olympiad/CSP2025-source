#include<bits/stdc++.h>
using namespace std;

vector<pair<string,string>> s;


int main(){
	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		s.push_back({s1,s2});
		
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int lent=t1.size();
		if(lent!=t2.size()) ans=0;
		else{
			for(int j=0;j<n;j++){
				if(t1==s[j].first && t2==s[j].second) ans++;
			}
			
			for(int i=0;i<lent;i++){
				
		}
		
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}