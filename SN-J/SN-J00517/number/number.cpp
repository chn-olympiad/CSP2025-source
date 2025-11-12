#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int t=s.size(),v[10]={0};
	for(int i=0;i<t;i++){
		if('0'<=s[i]&&s[i]<='9'){
			v[s[i]-'0']++;
		}
	}
	int sum=0;
	for(int i=9;i>=1;i--){
		sum+=v[i];
		for(int j=1;j<=v[i];j++){
			cout<<i;
		}
	}
	if(sum){
		for(int i=1;i<=v[0];i++)cout<<0;
	}
	else cout<<0;
	for(int i=0;i<=9;i++)cout<<v[i]<<" ";
	return 0;
}
