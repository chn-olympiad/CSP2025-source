#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m,n,b[101][101],a[101],h,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	int y=a[1];
	for(int i=1;i<=m*n;i++) {
		for(int j=1;j<=m*n;j++) {
			if(a[j]<=a[j+1]) {
				h=a[j];
				a[j]=a[j+1];
				a[j+1]=h;
			}
		}
	}
	for(int i=1;i<=n*m;i++) {
		if(a[i]==y){
			x=i;
		}
	}
	cout<<(x/4)+1;
	int u=x%4;
	if((x/4)%2==1) {
		cout<<n-u+1<<" ";
	}
	else{
		cout<<u;
	}
	fclose(stdin);
	fclose(stdout);
}
