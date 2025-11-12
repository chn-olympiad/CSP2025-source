#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
bool flag2,flag3;
struct stu{
	int a,b,c;
}a[100005];
bool cmp1(stu a,stu b){
	return a.a>b.a;
}
bool cmp2(stu a,stu b){
	return a.a+b.b>a.b+b.a;
}
void d(int x,int i,int j,int e,int num){
	if(x==n+1){
		ans=max(ans,num);
		return;
	}
	if(i<n/2) d(x+1,i+1,j,e,num+a[x].a);
	if(j<n/2) d(x+1,i,j+1,e,num+a[x].b);
	if(e<n/2) d(x+1,i,j,e+1,num+a[x].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;flag2=1;flag3=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b) flag2=0;
			if(a[i].c) flag3=0;
		}
		if(n<=30){
			d(1,0,0,0,0);
			printf("%d\n",ans);
		}
		else if(flag2&&flag3){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++) ans+=a[i].a;
			printf("%d\n",ans);
		}
		else if((!flag2)&&flag3){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++) ans+=a[i].a;
			for(int i=n/2+1;i<=n;i++) ans+=a[i].b;
			printf("%d\n",ans);
		}
		else{
			d(1,0,0,0,0);
			printf("%d\n",ans);
		}
	}
	return 0;
}
