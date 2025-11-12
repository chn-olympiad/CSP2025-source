#include<bits/stdc++.h>
using namespace std;
int cnt[10];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int n=s.size();
	int p=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt[s[i]-'0']++;
			p++;		
		}
	}
	if(cnt[0]==p){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
}