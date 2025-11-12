#include<bits/stdc++.h>
using namespace std;
int a[100010][3],b[3][100010],c[3],n,t,x,y;
long long int d[50010],s;
inline int read(){
	register int e=0;
	char f;
	f=getchar();
	while(f<48||f>57) f=getchar();
	while(f>47&&f<58){
		e=(e<<1)+(e<<3)+(f^48);
		f=getchar();
	}
	return e;
}
inline void print(long long int e){
	if(e<10){
		putchar(e^48);
		return;
	}
	print(e/10);
	putchar((e%10)^48);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		c[0]=c[1]=c[2]=0;
		for(register int i=0;i<=n/2;i++) d[i]=0;
		s=0;
		for(register int i=1;i<=n;i++){
			a[i][0]=read();
			a[i][1]=read();
			a[i][2]=read();
		}
		for(register int i=1;i<=n;i++){
			x=y=-1;
			for(register int j=0;j<3;j++){
				if(a[i][j]>y){
					x=j;
					y=a[i][j];
				}
			}
			b[x][c[x]++]=i;
		}
		for(register int i=0;i<3;i++){
			if(c[i]>n/2){
				for(register int j=0;j<c[i];j++){
					for(register int k=n/2;k>0;k--) d[k]=max(d[k]+max(a[b[i][j]][(i+1)%3],a[b[i][j]][((i-1)%3+3)%3]),d[k-1]+a[b[i][j]][i]);
					d[0]=max(d[0],(long long int)max(a[b[i][j]][(i+1)%3],a[b[i][j]][((i-1)%3+3)%3]));
				}
				s+=d[n/2];
			}
			else for(register int j=0;j<c[i];j++) s+=a[b[i][j]][i];
		}
		print(s);
		putchar('\n');
	}
	return 0;
}