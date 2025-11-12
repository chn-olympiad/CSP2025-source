#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char s[1000005];
int a[1000005],q=0,l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++){
		if(isdigit(s[i])){
			a[q++]=s[i]-'0';
		}
	}
	sort(a,a+q);
	for(int i=q-1;i>0;i--){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
