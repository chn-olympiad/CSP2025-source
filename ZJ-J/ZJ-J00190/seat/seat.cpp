#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=0;
	for (int i=1;i<=n*m;i++){
		if (a[i]==x){
			id=i;
			break;
		}
	}
	int l=(id+n-1)/n;
	id=(id-1)%n+1;
	int h=0;
	if (l%2==1){
		h=id;
	}
	if (l%2==0){
		h=n-id+1;
	}
	printf("%d %d\n",l,h);
	return 0;
}
