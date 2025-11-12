#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],k=1;
	sort(a+1,a+1+n*m);
	while(a[n*m-k+1]!=t){
		k++;
	}
	int c,r;
	c=(k-1)%(n*2)+1;
	r=((k-1)/(n*2))*2+1;
	if(c>n){
		r++;
		c=n*2-c+1;
	}
	printf("%d %d\n",r,c);
}
