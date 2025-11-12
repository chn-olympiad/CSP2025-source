#include<bits/stdc++.h>
using namespace std;
int n,m,r[105],b[105],a[15][15],i,j,k=1,kao,use;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	use=n*m;
	for(i=1;i<=use;i++) r[i]=read();
	kao=r[1];
	sort(r+1,r+use+1);
	k=use;
	for(i=1;i<=use;i++,k--) b[k]=r[i];
	k=1;
	for(i=1;i<=n;i++){
		if(i%2==1){
			for(j=1;j<=m;j++) a[j][i]=b[k],k++;
		}else{
			for(int j=m;j>0;j--) a[j][i]=b[k],k++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==kao){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
