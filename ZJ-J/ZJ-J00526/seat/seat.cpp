#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int a[15][15];
int b[105];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)b[i]=read();
	int x=1;
	for(int j=1;j<=m;j++){
		if(j&1){for(int i=1;i<=n;i++,x++)a[i][j]=x;}
		if(!(j&1)){for(int i=n;i>=1;i--,x++)a[i][j]=x;}
	}
	num=b[1];
	sort(b+1,b+1+n*m,cmp);
//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=m;j++)if(j==m)cout<<a[i][j]<<'\n';else cout<<a[i][j]<<" ";
	int k=1;
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				if(b[k]==num){cout<<j<<" "<<i<<'\n';return 0;}
				k++;
			}
		}
		if(!(j&1)){
			for(int i=n;i>=1;i--){
				if(b[k]==num){cout<<j<<" "<<i<<'\n';return 0;}
				k++;
			}	
		}
	}
	return 0;
}
