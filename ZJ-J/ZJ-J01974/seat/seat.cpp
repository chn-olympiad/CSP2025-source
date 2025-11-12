#include<bits/stdc++.h>
#define rint register int
using namespace std;
const int mxn=114;
int n,m,a[mxn],r;
inline int read(){
    int x=0;bool f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return f?-x:x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	n=read();m=read();
	for(rint i=1;i<=n*m;i++){
		a[i]=read();
		if(i==1)r=a[i];
	}
	sort(a+1,a+1+n*m);
	int x=1,y=1;
	for(rint i=n*m;i>=1;i--){
		if(a[i]==r){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2){
			if(x<n)x++;
			else y++;
		}
		else{
			if(x>1)x--;
			else y++;
		}
	}
    return 0;
}
/*
    Code is far away from
bug with the animal protecting
    神兽保佑，代码无bug
*/
