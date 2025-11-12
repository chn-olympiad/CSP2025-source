#include <bits/stdc++.h>
using namespace std;
int cnt[15];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for (int i=0;i<n;i++){
		int t=s[i]-'0';
		if (t>=0&&t<=9) cnt[t]++;
	}
	for(int i=9;i>=0;i--){
		if(cnt[i]!=0) {
			for(int j=1;j<=cnt[i];j++)
				cout<<i;
		}
	}
	return 0;
} 
