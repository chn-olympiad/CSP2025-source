#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int a[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')a[s[i]^'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	cout<<endl;
	return 0;
}
//11.1 8:38
//code by K.S.
