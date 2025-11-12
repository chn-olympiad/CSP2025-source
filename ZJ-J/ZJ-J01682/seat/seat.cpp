#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a,b,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<=n*m-1;i++){
		scanf("%d",&x);
		if(x>a){
			b++;
		}
	}
	cout<<b/n+1<<' ';
	if(b/n&1){
		cout<<n-b%n;
	}else{
		cout<<b%n+1;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
