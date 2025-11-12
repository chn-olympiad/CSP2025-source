#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<char('0'+i);
	}
	return 0;
}
