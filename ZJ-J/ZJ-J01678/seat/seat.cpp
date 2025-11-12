#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int rk=1;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	int s=read();
	for(int i=2;i<=n*m;i++){
		int x=read();
		if(x>s) rk++;
	}
	int c=ceil(1.0*rk/m);
	int r=rk-(c-1)*m;
	if(c%2==0){
		r=(m-r+1);
	}
	printf("%d %d\n",c,r);
	return 0;
}