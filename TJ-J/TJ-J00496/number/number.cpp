#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(!isdigit(s[i]))continue;
		int c=s[i]-'0';
		++cnt[c];
	}
	for(int i=9;i>=0;i--){
		if(cnt[i]==0)continue;
		for(int j=1;j<=cnt[i];j++)cout<<i;
	}
	cout<<'\n';
	return 0;
}

