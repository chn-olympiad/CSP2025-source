#include <iostream>
#include <cstring>
using namespace std;
struct r{
	int l=0;
	int h=0;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	struct b [n*m]{
	int l=0;//dijilie
	int h=0;//dijihang
	int cj=0;//chengji
};
	int s[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int a[n*m]={0};
	for(int i=1;i<=n*m-1;i++){
		if(s[i-1]>s[i]){
			a[i]=s[i];
			a[i-1]=s[i-1];
		}else if(s[i-1]<s[i]){
			a[i]=s[i-1];
			a[i-1]=s[i];
		}else{
			a[i]=a[i];
			a[i-1]=s[i-1];
		}
	}
	int c[m][n]={0};//zuowei
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[i][j]=(m-1)*n+n;
				b[(m-1)*n+n].l=i;
				b[(m-1)*n+n].h=j;
			}
		}
		if(i%2==0){
			for(int j=1;j<=n;j++){
				c[i][j]=m*n-n+1;
				b[m*n-n+1].l=i;
				b[m*n-n+1].h=j;
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		b[i].cj=s[i];
	}
	for(int i=1;i<=n;i++){
		if(s[1]==b[i].cj){
			r.l=b[i].l;
			r.h=b[i].h;
		}
	}
	cout<<r.l<<r.h;
	return 0;
}