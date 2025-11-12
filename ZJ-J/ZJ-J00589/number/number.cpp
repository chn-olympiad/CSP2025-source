#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'0';
		if(x>=0&&x<=9){
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}