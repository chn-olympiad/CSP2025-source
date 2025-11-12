#include<bits/stdc++.h>
using namespace std;
char g[1000009];
bool cmp(int a,int b){
	if(a>b) return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') g[x++]=s[i];
	}
	sort(g+1,g+x,cmp);
	for(int i=1;i<x;i++) cout<<g[i];
	return 0;
}
