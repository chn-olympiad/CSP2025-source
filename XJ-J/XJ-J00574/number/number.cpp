#include<bits/stdc++.h>
using namespace std;
char c;
string s;
int num[1000010],j=0,a=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(1){
		scanf("%c",&c);
		if(c=='\n') break;
		s[a]=c;
		a++;
	}
	for(int i=0;i<a;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			num[j]=s[i]-48;
			j++;
		}
	}
	sort(num,num+j,cmp);
	for(int i=0;i<j;i++){
		printf("%d",num[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
