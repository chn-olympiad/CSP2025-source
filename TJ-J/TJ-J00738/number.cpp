#include<iostream>
#include<string.h>
using namespace std;
int a[15];
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&i<='9'){
			a[n[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
