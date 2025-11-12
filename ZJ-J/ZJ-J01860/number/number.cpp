#include<bits/stdc++.h>
using namespace std;
char s[1100000];
long long int num[1200];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	int m=strlen(s+1);
	for(int i=1;i<=m;i++){
		if(s[i]>='0'&&s[i]<='9')num[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		//cout<<num[i]<<' ';
		for(int o=1;o<=num[i];o++){
			cout<<i;
		}
	}
	
	return 0;
}
