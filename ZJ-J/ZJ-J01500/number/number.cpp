#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt=1;
void read(){
	int ret=0,f=1;char ch=getchar();
	while(ch!='\n'){if(isdigit(ch)) a[cnt++]=ch-'0';ch=getchar();}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read();
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>0;i--) printf("%d",a[i]);
	printf("\n");
	return 0;
}
