#include<bits/stdc++.h>
using namespace std;
int n,m,val,cnt,nowx=0,nowy=1,a[105];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			scanf("%d",&a[++cnt]);
			if(i==1&&j==1)val=a[cnt];
		}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(nowx==1&&nowy%2==0)nowy++;
		else if(nowx==n&&nowy%2==1)nowy++;
		else if(nowy%2==0)nowx--;
		else if(nowy%2==1)nowx++;
		if(a[i]==val){
			printf("%d %d\n",nowy,nowx);
			return 0;
		}
	}
}