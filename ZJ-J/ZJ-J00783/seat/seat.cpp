#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[10005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int k = a[1],index = 1;
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i] == k){
			index = i;
			break;
		}
	}
	if(index%n!=0){
		if((index/n+1)%2==1){
			printf("%d %d",index/n+1,index%n);
		}
		else{
			printf("%d %d",index/n+1,n-index%n+1);
		}
	}
	else{
		if((index/n%2)==1){
			printf("%d %d",index/n,n);
		}
		else{
			printf("%d %d",index/n,1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
