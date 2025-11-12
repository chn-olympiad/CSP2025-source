#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int h=0,l=1;
	for(int i=1;i<=n*m;i++){
		if(l%2==1)h++;
		else h--;
		if(a[i]==t){
			printf("%d %d\n",l,h);
			break;
		}
		if(l%2==1 && h==n)l++,h++;
		else if(l%2==0 && h==1)l++,h=0;
	}
	return 0;
}
