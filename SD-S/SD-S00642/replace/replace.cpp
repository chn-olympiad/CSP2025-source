#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string s,ss;
		cin>>s>>ss;
		int cnt=0;
		for(int i=1;i<=n;i++){
			int len=s1[i].size(),len1=s.size();
			for(int j=0;j<=len1-len;j++){
				int flag=0;
				for(int k=0;k<s1[i].size();k++){
					if(s[j+k]!=s1[i][k]){
						flag=1;
						break;
					}
				}
				if(!flag){
//					cout<<s1[i]<<' ';
					string tmp=s;
					for(int k=j;k<j+s1[i].size();k++) s[k]=s2[i][k-j];
					if(s==ss){
						cnt++;
					}
					s=tmp;
				}
			}
		} 
		cout<<cnt<<'\n';
	}
	return 0;
}
