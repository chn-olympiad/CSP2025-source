#include<bits/stdc++.h>
using namespace std;
char a[1002000];
int sz[15];
int main(){
	int ok=0;
	cin>>a;
	int la=strlen(a);
	for(int i=0;i<la;i++){
		if(a[i]>='0' && a[i]<='9'){
			sz[(int)a[i]-48]++;
			if(a[i]>='1'){
				ok=1;
			}
		}
	}
	if(ok==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sz[i];j++){
			cout<<i;
		}
	}
	return 0;
}
