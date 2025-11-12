#include<bits/stdc++.h>
using namespace std;

int k[15];

int main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int z=s[i]-'0';
			k[z]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		char z=('0'+i);
		while(k[i]){
			cout<<z;
			k[i]--;
		}
	}
	return 0;
}
