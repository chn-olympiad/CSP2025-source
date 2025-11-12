#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],k,l=1,c=1,r=1;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	k=n*m;
	for(int i=1;i<=k;i++) a[i]=read();
	int p=a[1];
	sort(a+1,a+1+k,greater<int>());
	while(l<=n*m){
		if(a[l]==p){
			printf("%d %d",c,r);
			return 0;
		}
		if(c%2==0){
			if(r==1) c++;
			else r--;
		}
		else{
			if(r==n) c++;
			else r++;
		}
		l++;
	}
}
