#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[105];

int read(){
	int f=1,cnt=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))cnt=cnt*10+ch-'0',ch=getchar();
	return f*cnt;
}

bool cmp(const int &A,const int &B){
	return A>B;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	x=n*m;
	for(int i=1;i<=x;i++) a[i]=read();
	int y=a[1];
	sort(a+1,a+1+x,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int f=0;
	    if(i%2==1) 
		for(int j=1;j<=m;j++){
			if(a[++cnt]==y){
				printf("%d %d",i,j);
				f=1;
				break;
			}
		} 
		else for(int j=m;j>=1;j--){
			if(a[++cnt]==y){
				printf("%d %d",i,j);
				f=1;
				break;
			}
		}
		if(f==1)break;
	}
}
