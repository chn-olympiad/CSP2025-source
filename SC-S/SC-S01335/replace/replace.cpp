#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int n,m;
string s[200005][2];
int main(){
	fre("replace");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(m--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l,r,len=t1.size(),num=0;
		for(l=0;l<len&&t1[l]==t2[l];l++);
		for(r=len-1;r>=0&&t1[r]==t2[r];r--);
		for(int i=0;i<=n;i++){
			for(int lft=0;lft<=l;lft++){
				if(t1[lft]==s[i][0][0]&&t2[lft]==s[i][1][0]){
					string a=t1.substr(lft,s[i][0].size()),b=t2.substr(lft,s[i][1].size());
					if(a==s[i][0]&&b==s[i][1]){
						num++;
					}
				}
			}
		}
		cout<<num<<'\n';
	}
	return 0;
}