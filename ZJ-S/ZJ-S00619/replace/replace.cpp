#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
using namespace std;
long long read(){
	long long dat=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-t;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
long long n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long i,j;
	n=read();
	m=read();
	for(i=1;i<=m;i++){
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}