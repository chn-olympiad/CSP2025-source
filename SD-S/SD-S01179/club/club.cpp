#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],si[100005],d[100005];
bool cmp1(int x,int y){
	return min(a[x][1]-a[x][2],a[x][1]-a[x][3])<min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
}
bool cmp2(int x,int y){
	return min(a[x][2]-a[x][1],a[x][2]-a[x][3])<min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
}
bool cmp3(int x,int y){
	return min(a[x][3]-a[x][1],a[x][3]-a[x][2])<min(a[y][3]-a[y][1],a[y][3]-a[y][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//我就是上午不会整活但还想上迷惑行为大赏的那个
	//预计100pts+16pts+10~20pts+8pts = 134~144pts 
	//      如下 
	//所以那些 CPP里全是暴力代码，没有注释
	//明年再见吧
	//第一次考 CSP-S，后几个题我毫无头绪
	//做成这样就还是挺失落的
	//但感觉也寄了
	//感觉没有DFS我连那些暴力都写不出来，我是fw
	//虽然山东是竞赛中弱省
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		int cnta=0,cntb=0,cntc=0,cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			int maxx=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxx==a[i][1]) cnta++,si[i]=1;
			else if(maxx==a[i][2]) cntb++,si[i]=2;
			else cntc++,si[i]=3;
			sum+=maxx;
		}
		if(cnta>n/2){
			for(int i=1;i<=n;i++) if(si[i]==1) d[++cnt]=i;
			sort(d+1,d+cnt+1,cmp1);
			for(int i=1;i<=cnt-n/2;i++) sum-=min(a[d[i]][1]-a[d[i]][2],a[d[i]][1]-a[d[i]][3]);
		}
		if(cntb>n/2){
			for(int i=1;i<=n;i++) if(si[i]==2) d[++cnt]=i;
			sort(d+1,d+cnt+1,cmp2);
			for(int i=1;i<=cnt-n/2;i++) sum-=min(a[d[i]][2]-a[d[i]][1],a[d[i]][2]-a[d[i]][3]);
		}
		if(cntc>n/2){
			for(int i=1;i<=n;i++) if(si[i]==3) d[++cnt]=i;
			sort(d+1,d+cnt+1,cmp3);
			for(int i=1;i<=cnt-n/2;i++) sum-=min(a[d[i]][3]-a[d[i]][2],a[d[i]][3]-a[d[i]][1]);
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
