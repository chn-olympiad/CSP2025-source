#include<bits/stdc++.h>
using namespace std;
char a;
long long int t[50];
int main(){
	freopen("number,in","r",stdin);
	freopen("number,out","w",stdout);
	while(cin>>a){
		if(a>='0'&&a<='9') {
		t[int(a)-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++) cout<<i;
	}
	return 0;
} 
