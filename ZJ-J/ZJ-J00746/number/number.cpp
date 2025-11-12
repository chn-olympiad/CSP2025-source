#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int table[10]={};
	char a[1000001];
	cin>>a;
	for(int i=0; ;i++){
		if(a[i]>='0'&&a[i]<='9'){
			table[a[i]-'0']++;
		}
		if(a[i+1]=='\n'){
			break;
		}
	}
	for(int i=9;i>-1;i--){
		while(table[i]!=0){
			cout<<i;
			table[i]--;
		}
	}
	return 0;
}

