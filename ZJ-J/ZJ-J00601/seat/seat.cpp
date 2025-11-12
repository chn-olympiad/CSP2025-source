//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			id=i;
			break;
		}
	}
	int l=(id+n-1)/n;
	printf("%d ",l);
	int yu=(id-1)%n+1;
	if(l%2){
		printf("%d",yu);
	}
	else{
		printf("%d",n-yu+1);
	}
	return 0;
}