#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1001],n,m;
bool cmp(int pa,int pb){
	return pa>pb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	int l=n*m;
	for(int i=1;i<=l;i++){
		scanf("%d",&a[i]);
	}int p=a[1],now;
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==p){
			now=i;break;
		}
	}
	int t=now/n,y=now%n;
	if(!y) y=n;
	else t++;
	if(t&1){
		printf("%d %d\n",t,y);
	}else{
		printf("%d %d\n",t,n-y+1);
	}
	return 0;
}