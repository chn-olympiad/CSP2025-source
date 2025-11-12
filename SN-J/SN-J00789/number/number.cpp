#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string s;
	cin>>s;
	int b[1000]={0};
	for(int i=0;i<1000;i++){
		if('s[i]'>='0' && 's[i]'<='9'){
			b[i]=s[i]+1;
		}
	}
	for(int i=0;i<1000;i++){
		for(int j=i+1;j<1000;j++){
			if(b[j]>b[i])
			{
				int a=b[i];
				b[i]=b[j];
				b[j]=a;
			}
		}
	}
	for(int i=0;i<1000;i++){
		if(b[i]!=0){
			cout<<b[i]-1;
		}
	}
	return 0;
}
