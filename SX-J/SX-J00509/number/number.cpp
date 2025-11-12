#include<bits/stdc++.h>
using namespace std;
char c;
int cnt[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>c){
		cnt[(int)c]++;
	}
	while(cnt['9']--) cout<<9;
	while(cnt['8']--) cout<<8;
	while(cnt['7']--) cout<<7;
	while(cnt['6']--) cout<<6;
	while(cnt['5']--) cout<<5;
	while(cnt['4']--) cout<<4;
	while(cnt['3']--) cout<<3;
	while(cnt['2']--) cout<<2;
	while(cnt['1']--) cout<<1;
	while(cnt['0']--) cout<<0;
	return 0;
}
