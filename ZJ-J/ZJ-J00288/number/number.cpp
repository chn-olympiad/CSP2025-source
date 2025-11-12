#include<iostream>
#include<cstdio>
using namespace std;
int a[11]{},ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[str[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){ans++;
				printf("%d",i);
			}
		}
	}printf("\n");
	return 0;
}