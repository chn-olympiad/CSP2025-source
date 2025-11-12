#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long T,n,k,ans1,ans2,ans3,ans4,ans5,ans6;
struct club{int a,b,c;}a[maxn];
bool cmp1(club x,club y){return x.a+y.b>y.a+x.b;}
bool cmp2(club x,club y){return x.a+y.c>y.a+x.c;}
bool cmp3(club x,club y){return x.b+y.c>y.b+x.c;}
namespace force{
long long r[maxn],ans;
void dfs(int pos,int c1,int c2,int c3,int lst){
	if(pos==n+1){
		long long s=0;
		for(int i=1;i<=n;i++) s+=r[i];
		ans=max(ans,s);
		return;
	}
	for(int i=lst+1;i<=n;i++){
		if(c1<k) r[pos]=a[i].a,dfs(pos+1,c1+1,c2,c3,i);
		if(c2<k) r[pos]=a[i].b,dfs(pos+1,c1,c2+1,c3,i);
		if(c3<k) r[pos]=a[i].c,dfs(pos+1,c1,c2,c3+1,i);
	}
}
int main(){
	ans=0,memset(r,0,sizeof(r)),dfs(1,0,0,0,0),cout<<ans<<'\n';
	return 0;
}
}
int check(){
	for(int i=1;i<=n;i++){
		if(a[i].c) return 0;
		if(a[i].b) return 2;
	}
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n,k=n/2,ans1=ans2=ans3=ans4=ans5=ans6=0;
		for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
		if(n<=10){force::main();continue;}
		int c=check();
		if(c==1){
			long long ans=0;
			for(int i=1;i<=n;i++) ans+=a[i].a;
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+n+1,cmp1),sort(a+k+1,a+n+1,cmp2);
		for(int i=1;i<=k;i++) ans1+=a[i].a;
		for(int i=k+1;i<=n;i++) ans1+=a[i].b;
		sort(a+1,a+n+1,cmp1),sort(a+k+1,a+n+1,cmp3);
		for(int i=1;i<=k;i++) ans2+=a[i].a;
		for(int i=k+1;i<=n;i++) ans2+=a[i].c;
		sort(a+1,a+n+1,cmp2),sort(a+k+1,a+n+1,cmp1);
		for(int i=1;i<=k;i++) ans3+=a[i].b;
		for(int i=k+1;i<=n;i++) ans3+=a[i].a;
		sort(a+1,a+n+1,cmp2),sort(a+k+1,a+n+1,cmp3);
		for(int i=1;i<=k;i++) ans4+=a[i].b;
		for(int i=k+1;i<=n;i++) ans4+=a[i].c;
		sort(a+1,a+n+1,cmp3),sort(a+k+1,a+n+1,cmp1);
		for(int i=1;i<=k;i++) ans5+=a[i].c;
		for(int i=k+1;i<=n;i++) ans5+=a[i].a;
		sort(a+1,a+n+1,cmp3),sort(a+k+1,a+n+1,cmp2);
		for(int i=1;i<=k;i++) ans6+=a[i].c;
		for(int i=k+1;i<=n;i++) ans6+=a[i].b;
		cout<<max({ans1,ans2,ans3,ans4,ans5,ans6})<<'\n';
	}
	return 0;
}
/*
By ZJ-S01763.
Luogu UID:1086453.
*/
