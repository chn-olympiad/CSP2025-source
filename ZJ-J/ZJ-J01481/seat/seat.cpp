#include<bits/stdc++.h>
using namespace std;
const int MAXN=100+5;
const int inf=2147483647;
//
int r,n,m,ans;
int a[MAXN];
//
bool cmp(int x,int y){
	return x>y;
}
//
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	/*for(int i=1;i<=n*m;++i){
		printf("%d ",a[i]);
	}cout<<"\n";*/
	for(int i=1;i<=n*m;++i){
		if(a[i]==r){
			ans=i;
			break;
		}
	}
	int h=0,l=0,x=0;
	if(ans<n){
		h=ans;
		l=1;
		printf("%d %d",l,h);
		return 0;
	}
	else {
		x=ans/n;
		if(ans%n==0){
			if(x%2==0){
				h=1;
				l=x;
			}else {
				h=n;
				l=x;
			}
		}else {
			if(x%2==0){
				h=ans%n;
				l=x+1;
			}else {
				h=n-ans%n+1;
				l=x+1;
			}
		}
	}
	printf("%d %d",l,h);
/*
2 2
98 99 100 97
*/
	return 0;
}