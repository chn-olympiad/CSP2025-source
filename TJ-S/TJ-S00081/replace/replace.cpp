#include<bits/stdc++.h>
using namespace std;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i][0].size()<=s1.size();j++){
				//cout<<s1.substr(j,s[i][0].size())<<" "<<s[i][0]<<"\n";
				if(s1.substr(j,s[i][0].size())==s[i][0]){
					string S1=s1;
					for(int k=j;k<j+s[i][0].size();k++){
						S1[k]=s[i][1][k-j];
					}
					//cout<<S1<<" "s[i]<<s2<<"\n";
					if(S1==s2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
