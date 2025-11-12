#include<bits/stdc++.h>
using namespace std;
int T,n,ans,t1,t2,t3,a[100005],b[100005],c[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		t1=0;
		t2=0;
		t3=0;
		scanf("%d",&n);
		for(int i=1,x,y,z;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			int ma=x,cd=-1,id=1;
			if(y>ma){
				cd=ma;
				ma=y;
				id=2;
			}else if(y>cd){
				cd=y;
			}
			if(z>ma){
				cd=ma;
				ma=z;
				id=3;
			}else if(z>cd){
				cd=z;
			}
			if(id==1){
				t1++;
				a[t1]=ma-cd;
			}else if(id==2){
				t2++;
				b[t2]=ma-cd;
			}else{
				t3++;
				c[t3]=ma-cd;
			}
			ans+=ma;
		}
		if(t1*2>n){
			sort(a+1,a+1+t1,cmp);
			for(int i=n/2+1;i<=t1;i++){
				ans-=a[i];
			}
		}
		if(t2*2>n){
			sort(b+1,b+1+t2,cmp);
			for(int i=n/2+1;i<=t2;i++){
				ans-=b[i];
			}
		}
		if(t3*2>n){
			sort(c+1,c+1+t3,cmp);
			for(int i=n/2+1;i<=t3;i++){
				ans-=c[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//0d000721
/*
3
4 
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
