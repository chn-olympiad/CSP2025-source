#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int rf,rc;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	rf=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==rf){
			rc=i;
			break;
		}
	}
	rc-=1;
	cout<<(rc/n+1)<<" ";
	if((rc/n+1)%2==1){
		cout<<(rc%n+1);
	}
	else{
		cout<<(n-rc%n);
	}
	
	
	return 0;
}
