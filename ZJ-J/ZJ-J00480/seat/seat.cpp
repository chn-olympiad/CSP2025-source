#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int N=n*m;
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
	int sry=a[1],id=0;
	sort(a+1,a+N+1,cmp);
	for(int i=1;i<=N;i++){
		if(a[i]==sry){
			id=i; break;
		}
	}
	int r=(id+n-1)/n;
	int c=id%n;
	if(!c) c=n;
	if(r%2==0) c=n-c+1;
	printf("%d %d\n",r,c); 
	return 0;
}
