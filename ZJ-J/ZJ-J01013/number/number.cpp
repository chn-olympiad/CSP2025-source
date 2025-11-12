#include<bits/stdc++.h>
using namespace std;
int c[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]>='0'&&x[i]<='9'){
			c[x[i]-'0']+=1;
		}
	}for(int i=9;i>=0;i--){
		while(c[i]){
			cout<<i;
			c[i]-=1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
