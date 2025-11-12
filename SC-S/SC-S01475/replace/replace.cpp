#include <bits/stdc++.h>
using namespace std;
unordered_map <string,string> mp;
int n,q;
string s1;
string s2;
string x,y,z,xx,yy,zz;
bool f=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		long long ans=0;
		cin>>s1>>s2;
		int len=s1.size();
		for(int i=0;i<len;i++){
			for(int j=i;j<len;j++){
				y=s1.substr(i,(j-i+1));
				x=s1.substr(0,0+i);
				if(j+1<len) z=s1.substr(j+1,len-j-1);
				
				yy=s2.substr(i,(j-i+1));
				xx=s2.substr(0,0+i);
				if(j+1<len) zz=s2.substr(j+1,len-j-1);
				
				if(xx==x && z==zz){
					if(yy==y || yy==mp[y]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
	
} 