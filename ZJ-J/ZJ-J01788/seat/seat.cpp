#include<bits/stdc++.h>
using namespace std;
int m,n,r,w;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m*n;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r) w=i;
	}
	if((int)((w-1)/n)%2==0) {
		cout<<(int)((w-1)/n)+1<<" "<<(w-1)%n+1;
	}
	else{
		cout<<(int)((w-1)/n)+1<<" "<<n-(w-1)%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
