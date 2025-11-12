#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct stu{
	int id;
	int x;
	int y;
}f[N];
int p[N]; 
int a,b,c;
int n,ans;
bool cmp(int a,int b){
	return a>b;
}
bool cmp2(stu a,stu b){
	return a.x<b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		if(n==2){
			int d,e,f;
			scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
			printf("%d\n",max(a+e,max(a+f,max(b+d,max(b+f,max(c+d,c+e))))));
			continue;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			ans+=a;
			p[i]=b-a;
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=p[i];
		}
		printf("%d",ans);
	}
	return 0;
}

