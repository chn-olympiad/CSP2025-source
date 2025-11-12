#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
int n,m,a[105],x,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n*m;i++){
		a[i]=read();
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			c++;
		}
	}
	cout<<1+c/n<<" ";
	if((1+c/n)%2==1){
		cout<<1+c%n;
	}
	else{
		cout<<m-c%n;
	}
	return 0;
}
