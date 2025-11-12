#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))a[s[i]-'0']++;
	}
	bool f=false;
	for(int i=9;i>=1;i--){
		if(i!=0&&a[i]!=0)f=true;
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	if(f)for(int i=1;i<=a[0];i++)cout<<0;
	else cout<<0;
	return 0;
}
