#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={0};
	for(int i=0;i<s.size();++i){
		char c=s[i];
		if(c>='0'&&c<='9'){
			a[c-'0']++;
		}
	}for(int i=9;i>=0;--i){
		for(int j=1;j<=a[i];++j){
			cout<<i;
		}
	}
	return 0;
}
