#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int z=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z=1;
			a[s[i]-'0']++;
		}
	}
	if(z==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}
