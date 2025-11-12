#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
char s[N];
int a[N];
int k=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=(int)s[i]-'0';
		}
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		printf("%d",a[i]);
	}
	return 0;
}