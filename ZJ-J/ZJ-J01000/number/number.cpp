#include<bits/stdc++.h>
using namespace std;
int g[1000009],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			g[++cnt]=s[i]-'0';
		}
	}
	sort(g+1,g+1+cnt);
	if(g[cnt]==0)cout<<0;
	else{
		for(int i=cnt;i>=1;i--)cout<<g[i];
	}
	return 0;
}
