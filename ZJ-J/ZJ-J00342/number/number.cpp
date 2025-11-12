#include<bits/stdc++.h>;
using namespace std;
string a;
int nu[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]>='0'&&a[i]<='9'){
			nu[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=nu[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
