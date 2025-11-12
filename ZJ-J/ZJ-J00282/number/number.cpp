#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	bool f=0;
	for(int i=9;i>0;i--){
		if(a[i]>0){
			f=1;
			for(int j=0;j<a[i];j++){
				printf("%d",i);
			}
		}
	}
	if(f){
		for(int j=0;j<a[0];j++){
			printf("0");
		}
	}
	else{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
