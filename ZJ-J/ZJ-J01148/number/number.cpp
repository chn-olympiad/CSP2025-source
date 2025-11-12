#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;

string s;
int a[maxn],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}bool f=0;
	for(int i=9;i>=1;i--){
		if(a[i]!=0){
			f=1;
			for(int j=1;j<=a[i];j++)cout<<i;
		}
	}
	if(f==0)cout<<0;
	else{
		for(int j=1;j<=a[0];j++)cout<<0;
	}
	
	return 0;
}