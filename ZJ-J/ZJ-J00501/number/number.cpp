#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=100;
int num[N];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')num[s[i]-'0']++;
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++)cout<<i;
	}
	return 0;
}
