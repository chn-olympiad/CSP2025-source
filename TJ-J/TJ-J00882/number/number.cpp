#include<bits/stdc++.h>
using namespace std;
int a[100000] = {0};
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int x = 0;
	for(int i = 0;i<s.length();i++){
		if(s[i]<65){
			a[x] = s[i]-'0';
			x++;
		}
	}
	sort(a,a+x);
	for(int j = x-1;j>=0;j--){
		cout<<a[j];
	}
	return 0;
}
