#include<bits/stdc++.h>
using namespace std;
const int maxn=105;

int n,m,a[maxn];
int res,p,q;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	res=a[1];
	sort(a+1,a+n*m+1,cmp);
	p=1;
	q=0;
	for (int i=1;i<=n*m;i++){
		if (p%2==1){
			if (++q>n){
				q=n;
				p++;
			}
		}else{
			if (--q<1){
				q=1;
				p++;
			}
		}
		if (a[i]==res){
			break;
		}
	}
	printf("%d %d",p,q);
	return 0;
}
