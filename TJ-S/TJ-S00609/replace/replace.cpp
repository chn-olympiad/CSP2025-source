#include <bits/stdc++.h>
using namespace std;
bool ILoveLrh(string t,string s,int p){
	int o=0;
	for(int i=p;i<=p+s.size()-1;i++,o++){
		if(t[i]!=s[o])return false;
	}
	return true;
}
string LrhLovesMe(string t,string s,int p){
	int o=0;
	for(int i=p;i<=p+s.size()-1;i++,o++){
		t[i]=s[o];
	}
	return t;
}
int n,q,ct,sc;
string t1,t2,s[200010][4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q --> 0){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				ct=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				ct=i-ct+1;
				break;
			}
		}
		sc=0;
		for(int i=1;i<=n;i++){
			if(s[i][1].size()<ct)continue;
			for(int j=0;j<t1.size()-s[i][1].size()+1;j++){
				if(ILoveLrh(t1,s[i][1],j)){
					if(LrhLovesMe(t1,s[i][2],j)==t2)sc++;
				}
			}
		}
		cout<<sc<<endl;
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
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
