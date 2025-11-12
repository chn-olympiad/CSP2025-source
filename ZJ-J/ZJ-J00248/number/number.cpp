#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int l=sizeof(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int a=s[i]-'0';
			cnt[a]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
}