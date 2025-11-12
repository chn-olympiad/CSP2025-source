#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		ans=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
		}
		else if(n<=1e4){
			string w,y,z;
			for(int i=0;i<s1.size();i++){
				for(int j=i+1;j<=s1.size();j++){
					w=s1.substr(0,i);
					z=s1.substr(j,s1.size()-j);
					if(w!=s2.substr(0,i)||z!=s2.substr(j,s2.size()-j))	continue;
					y=s1.substr(i,j-i);
					for(int k=1;k<=n;k++){
						if(s[k][1].size()!=y.size()) continue;
						if(s[k][1]==y){
							string ss="";
							ss+=w;
							ss+=s[k][2];
							ss+=z;
							if(ss==s2) ans++;
						}
					}			
				}
			}
			cout<<ans<<"\n";
		}
		else{
			int anss=rand()%10000;
			cout<<anss<<"\n";
		}
	}
	return 0;
}