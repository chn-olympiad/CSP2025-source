#include<bits/stdc++.h>
using namespace std;
int n,m,sr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d %d",&n,&m,&sr);
	int sum=1;
	for(int i=2;i<=n*m;i++){
		int a; 
		scanf("%d",&a);
		if(a>sr) sum++;
	}
	int c=sum/n+(sum%n != 0 ? 1:0);
	int r=(sum-1)%n+1;
	if(c%2==0){
		r=n-r+1;
	}
	printf("%d %d",c,r);
	return 0;
}
