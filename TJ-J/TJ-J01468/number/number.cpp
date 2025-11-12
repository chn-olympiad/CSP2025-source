#include<bits/stdc++.h>
using namespace std;
int sz[1000010];
int xbs=1;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int a=0;a<s.length();++a){
		if(s[a]>='0'&&s[a]<='9'){
			sz[xbs]=s[a]-'0';
			++xbs;
		}
	}
	--xbs;
	sort(sz+1,sz+xbs+1);
	for(int a=xbs;a>=1;--a){
		cout<<sz[a];
	}
	return 0;
}
