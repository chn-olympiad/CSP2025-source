#include<bits/stdc++.h>
#define lnt unsigned long long
#define N 2114514
using namespace std;
string s[N][2];
unordered_map<string,string > ss; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("relpace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		ss[s[i][0]]=s[i][1];
		ss[s[i][1]]=s[i][0];
		
	} 
	
	while(q--){
		string t1,t2;cin>>t1>>t2;
		string x,xp;
		int ans=0;
		t1="="+t1;
		t2="="+t2;
		for(int i=0;i<t1.size();i++){
			x=x+t1[i];
			xp=xp+t2[i];
			if(x!=xp){
				break;
			}
			string y,z,yp,zp;
			for(auto a:ss){
				if(a.first.size()+i>=t1.size()){
					continue;
				}
				y=t1.substr(i+1,(a.first.size() ) );
				if(y==a.first){
					yp=t2.substr(i+1,(a.first.size() ));
					
					if(a.second==yp){
						z=t1.substr(i+1+(a.first.size()));
						zp=t2.substr(i+1+(a.first.size()));
						if(z==zp||z.size()==0){
							ans++;
						} 
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}


