#include<bits/stdc++.h>
using namespace std;
string s;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0')a[s[i]-'0']++;
	}
	int i=9;
	while(i>=0){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
		i--;
	}
	return 0;
}
