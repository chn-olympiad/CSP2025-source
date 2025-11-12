#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll num[10];
bool f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z')continue;
		int c=s[i]-'0';
		num[c]++;
		if(c!=0)f=1;
	}
	if(!f){
		cout<<'0';
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(num[i]--)
			cout<<i;
	}
	return 0;
}

