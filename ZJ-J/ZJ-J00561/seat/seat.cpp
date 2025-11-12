#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cstdlib>
using namespace std;
int read(){
	int dat=0,t=1;
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
int n,m,k,t,l,r,a[200004];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j;
	n=read();
	m=read();
	a[1]=read();
	k=a[1];
	for(i=2;i<=n*m;i++){
		a[i]=read();
	}
	sort(a+1,a+n*m+1,cmp);
	for(j=1;j<=n*m;j++){
		if(a[j]==k){
			t=j;
			break;
		}
	}
	l=(t+n-1)/n;
	if(l%2==1){
		r=1+(t+n-1)%n;
	}else{
		r=n-(t+n-1)%n;
	}
	printf("%d %d",l,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

