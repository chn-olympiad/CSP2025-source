#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int rd(){int res=0,f=1;char x=getchar();
	while(x<'0'||'9'<x){if(x=='-')f*=-1;x=getchar();}
	while('0'<=x&&x<='9')res=res*10+x-'0',x=getchar();
return res*f;}
void wt(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)wt(x/10);
	putchar(x%10+'0');
return;}
const int N=1e5+100;
struct tmp{
	int t,id;
};
struct node{
	tmp val[3];
}a[N];int n;
bool cmp(node xx,node yy){
	return xx.val[0].t-xx.val[1].t==yy.val[0].t-yy.val[1].t?
				xx.val[0].t-xx.val[2].t>yy.val[0].t-yy.val[2].t:
				xx.val[0].t-xx.val[1].t>yy.val[0].t-yy.val[1].t;
}
bool cmp1(tmp xx,tmp yy){
	return xx.t>yy.t;
}
int cnt[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=rd();
	while(T--){
		n=rd();cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			a[i].val[0].t=rd(),a[i].val[0].id=0;
			a[i].val[1].t=rd(),a[i].val[1].id=1;
			a[i].val[2].t=rd(),a[i].val[2].id=2;
			sort(a[i].val,a[i].val+3,cmp1);	
		}sort(a+1,a+1+n,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].val[0].id]<n/2)
				++cnt[a[i].val[0].id],ans+=a[i].val[0].t;
			else if(cnt[a[i].val[1].id]<n/2)
				++cnt[a[i].val[1].id],ans+=a[i].val[1].t;
			else if(cnt[a[i].val[2].id]<n/2)
				++cnt[a[i].val[2].id],ans+=a[i].val[2].t;
		}wt(ans),putchar(endl);
	} 
	return 0;
}

