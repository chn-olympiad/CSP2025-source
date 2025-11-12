#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[110000]={};
	int b[110000]={};
	cin>>s;
for(int i=0;i<=strlen(s)-1;i++){
		if(s[i]=='1') b[i]=s[i];
		if(s[i]=='2') b[i]=s[i];
		if(s[i]=='3') b[i]=s[i];
		if(s[i]=='4') b[i]=s[i];
		if(s[i]=='5') b[i]=s[i];
		if(s[i]=='6') b[i]=s[i];
		if(s[i]=='7') b[i]=s[i];
		if(s[i]=='8') b[i]=s[i];
		if(s[i]=='9') b[i]=s[i];
		if(s[i]=='0') b[i]=s[i];
	}
	int num=0;
	for(int k=0;k<=strlen(s)-1;k++){
		if(b[k]!=0) num++;
	}
	for(int i=0;i<=strlen(s)-1;i++){
		for(int j=i-1;j>=0;j--){
		if(b[j]<b[j+1])	{
			swap(b[j],b[j+1]);
		}
	}
 }
	for(int i=0;i<=num-1;i++){
		cout<<b[i]-'0';
	}
	return 0;
}
