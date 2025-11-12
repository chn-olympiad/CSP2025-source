#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}
const int maxn=100005;
int n,t,ct[5],ps[5],maxa[5],ans;
bool f[maxn];
struct YXZ{
	int w,p;
	bool operator<(const YXZ &b)const{return w>b.w;}
};
struct fra{
	YXZ r[5];
	bool operator<(const fra &b)const{return r[1].p<b.r[1].p||r[1].p==b.r[1].p&&r[1].w>b.r[1].w;}
}a[maxn];
//bool cmp1(fra a,fra b){
//	return r[1].p<b.r[1].p||r[1].p==b.r[1].p&&r[1].w>b.r[1].w;
//}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		ans=0;
		memset(f,0,sizeof f);
		n=read();
		for(int i=1;i<=n;i++){
			a[i].r[1]=(YXZ){read(),1},a[i].r[2]=(YXZ){read(),2},a[i].r[3]=(YXZ){read(),3};
//			sort(a[i].r+1,a[i].r+1+3);
		}
//		sort(a+1,a+1+n);
		for(int i=1;i<=n/2;i++)ans+=a[i].r[1].w;
		printf("%d\n",ans);
	}
	return 0;
}