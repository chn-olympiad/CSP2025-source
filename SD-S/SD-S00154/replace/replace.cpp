#include<bits/stdc++.h>
#define size_t int 
using namespace std;
string s[200005][3]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(q--){
		int ans=0;
		string s1,s2,ss;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s1.size();j++){
				ss=s1;
				int flag=0;
				for(int k=0;k<s[i][1].size();k++){
					if(s1[j+k]!=s[i][1][k]){
						flag=1;
						break;
					}	
				}
				if(!flag){
					for(int k=0;k<s[i][1].size();k++)
						ss[j+k]=s[i][2][k];
					if(ss==s2){ ans++;}
				}
			}
		}
		cout<<ans<<'\n';
	}
//	while(q--) cout<<"0\n";
	return 0;
}
