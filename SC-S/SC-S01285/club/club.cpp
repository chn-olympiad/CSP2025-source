#include<bits/stdc++.h>
using  namespace std;
#define ll long long
const int N= 1e5+10;
struct student{
	int a1,a2,a3,id,c;
	int ma1,ma2;
	map<int,int>m;
}stu[N];
int cnt[4],ans;
bool cmp(student a,student b){
	if(a.c!=b.c)return a.c>b.c;
	if(a.ma1!=b.ma1)return a.ma1>b.ma1;
	if(a.ma2!=b.ma2)return a.ma2<b.ma2;
	return a.id<b.id;
}
void solve(){
	memset(cnt,0,sizeof(cnt));
	ans=0;
	int n;
	scanf("%d",&n);
	int lm=n/2;
	for(int i=1;i<=n;i++){
		int a[3];
		scanf("%d%d%d",&stu[i].a1,&stu[i].a2,&stu[i].a3);
		a[0]=stu[i].a1,a[1]=stu[i].a2,a[2]=stu[i].a3;
		sort(a,a+3);
		stu[i].ma1=a[2],stu[i].ma2=a[1],stu[i].c=a[2]-a[1];
		stu[i].m[stu[i].ma1]=0;stu[i].m[stu[i].ma2]=0;
		if(stu[i].ma1==stu[i].a1)stu[i].m[stu[i].ma1]=1;
		else if(stu[i].ma1==stu[i].a2)stu[i].m[stu[i].ma1]=2;
		else if(stu[i].ma1==stu[i].a3)stu[i].m[stu[i].ma1]=3;
		if(stu[i].ma2==stu[i].a1&&!stu[i].m[stu[i].ma2])stu[i].m[stu[i].ma2]=1;
		else if(stu[i].ma2==stu[i].a2&&!stu[i].m[stu[i].ma2])stu[i].m[stu[i].ma2]=2;
		else if(stu[i].ma2==stu[i].a3&&!stu[i].m[stu[i].ma2])stu[i].m[stu[i].ma2]=3;
		stu[i].id=i;
	}
	sort(stu+1,stu+1+n,cmp);
	for(int i=1;i<=n;i++){
		int maxx1=stu[i].ma1,maxx2=stu[i].ma2;
		if(cnt[stu[i].m[maxx1]]<lm){
			cnt[stu[i].m[maxx1]]++;
			ans+=maxx1;
		}else {
			cnt[stu[i].m[maxx2]]++;
			ans+=maxx2;
		}
	}
	printf("%d\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}