#include<bits/stdc++.h>
using namespace std;
string s;
int v[10],t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s){
		if(i>='0'&&i<='9'){
			t=i-48;
			v[t]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(v[i]!=0){
			for(int j=1;j<=v[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
