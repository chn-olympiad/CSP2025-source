#include<bits/stdc++.h>
using namespace std;
int a[201];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int p=n*m;
	for(int i=1;i<=p;i++){
		scanf("%d",&a[i]);
	}
	int s=0;
	for(int i=1;i<=p;i++){
		if(a[i]>=a[1]){
			s++;
		}
	}
	int l=s/n;
	int h;
	if(s%n!=0){
		l++;
		if(l%2==1){
			h=s%n;
		}
		else{
			h=n-s%n+1;
		}
		printf("%d %d",l,h);
	}
	else{
		if(l%2==1){
			printf("%d %d",l,n);
		}
		else{
			printf("%d %d",l,1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
