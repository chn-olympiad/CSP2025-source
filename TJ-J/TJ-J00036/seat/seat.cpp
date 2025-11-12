#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,a[105],y,wz;
bool cmp(long long n1,long long n2){
	return n1>n2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	y=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[n*(i-1)+(n-j+1)]==y){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(a[n*(i-1)+j]==y){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

