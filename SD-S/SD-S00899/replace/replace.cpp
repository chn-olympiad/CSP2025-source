#include<bits/stdc++.h>
using namespace std;

map<string,string> ma;

int n,q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		ma[s1]=s2;
	}
	while(q--){
		string s1,s2;
		int ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			printf("0\n");
			continue;
		}
		string s5[s1.size()+1];
		s5[s1.size()-1]=s1[s1.size()-1];
		for(int i=s1.size()-2;i>=0;i--){
			s5[i]=s1[i]+s5[i+1];
		}
		string s4="";
		for(int i=0;i<s1.size();i++){
			if(i!=0)s4+=s1[i-1];
			string s3="";
			for(int j=i;j<s1.size();j++){
				s3+=s1[j];
				if(ma[s3]!=""){
					if(s4+ma[s3]+s5[j+1]==s2)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
