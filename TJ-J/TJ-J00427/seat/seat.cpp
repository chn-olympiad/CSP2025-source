#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b,c,cnt,ha,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	b=n*m;
	for(int i=1;i<=b;i++){
		scanf("%d",&a[i]);
	}
	c=a[1];
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--){
		if(a[i]==c){
			cnt=b-i+1;
			break;
		}
	}
	ha=(cnt+n-1)/n;
	if(ha%2==1){
		l=cnt-n*(ha-1);
	}
	else if(ha%2==0){
		l=n-(cnt-n*(ha-1))+1;
	}
	printf("%d %d\n",ha,l);
	return 0;
} 
