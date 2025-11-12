#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],que[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int head=1,tail=0,R=0;
	for(int i=1;i<=n*m;i++){
		int tal=tail;
		while(head<=tal&&a[que[tal]]<a[i]){tal--;}
		for(int j=tail;j>tal;j--)que[j+1]=que[j];
		que[++tal]=i,tail++;
	}
	for(int i=head;i<=tail;i++){
		if(que[i]==1){
			R=i;
			break;
		}
	}
	int x=1,y=0;
	while(R>n){
		R-=n;
		x++;
	}
	if(x%2==1)y=R;
	else y=n-R+1;
	printf("%d %d\n",x,y);
//	for(int i=1;i<=n*m;i++)printf("%d\n",a[que[i]]);
	return 0;
}
