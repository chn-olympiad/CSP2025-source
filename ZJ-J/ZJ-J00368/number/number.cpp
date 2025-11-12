#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;
	cin>>t;
	int la=t.length(),n=0;
	for(int i=0;i<la;i++){
		if(t[i]>='0' && t[i]<='9'){
			a[t[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

