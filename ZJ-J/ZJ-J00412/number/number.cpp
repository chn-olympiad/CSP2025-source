#include<iostream>
#include<cstdio>
using namespace std;
char a[1000002];
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	scanf("%s",a);
	for(int i=0;a[i]!=0;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[a[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<t[i];j++) printf("%d",i);
	}
	return 0;
}
