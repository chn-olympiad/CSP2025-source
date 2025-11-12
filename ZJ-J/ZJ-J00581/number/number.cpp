#include<bits/stdc++.h>

using namespace std;

string s;
int cnt[20];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(cnt[i]--)
			cout<<i;
	}
	return 0;
}