#include<bits/stdc++.h>
using namespace std;
long long n,q;
map <string,string> mp;
struct node{
	string str,str1;
}p[200005];
string s,s1;
bool cmp(string a,string b){
	if(a.size()!=b.size()) return false;
	else{
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]) return false;
		}
		return true;
	}
}
long long add;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s>>s1;
		mp[s]=s1;
	}
	for(int i=1;i<=q;i++){
		cin>>s>>s1;
		for(int l=0;l<s.size()-1;l++){
			for(int le=1;le<=s.size()-l;le++){
				if(mp[s.substr(l,le)].empty()==false){
					string ss=s;
					ss.replace(l,le,mp[s.substr(l,le)]);
					if(cmp(s1,ss)==true) add++;
				}
			}
		}
		printf("%lld\n",add);
		add=0;
	}
	return 0;
}
