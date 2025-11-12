# include <bits/stdc++.h>
using namespace std;
string s;
int k[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<=int(s.length());i++){
		if(s[i]>='0'&&s[i]<='9'){
			int n=s[i]-'0';
			for(int i=0;i<=9;i++){
				if(n==i) k[i]++;
			}
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<=k[i]-1;j++){
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
	// 2025-11-1 9:22
}
