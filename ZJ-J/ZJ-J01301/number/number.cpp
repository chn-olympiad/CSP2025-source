#include<bits/stdc++.h>
using namespace std;
string s;
int num[20];
int cnt,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		n=s[i]-'0';
		if(n>=0&&n<=9){
			num[n]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
