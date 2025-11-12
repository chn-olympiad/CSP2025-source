#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> PII;//满意度 编号 大小(1,2,3) 
const int N=1e5+10;
int n,ans,cnta,cntb,cntc;
int a[N],b[N],c[N];
struct node{
	int x,y,z,id;
}p[N];
int getmax(int x){
	return max(max(a[x],b[x]),c[x]);
}
int getmin(int x){
	return min(min(a[x],b[x]),c[x]);
}
int getmid(int x){
	return a[x]+b[x]+c[x]-getmax(x)-getmin(x);
}
vector<int> res;
void dfs(int now,int tot){
	if(now>n){
		if(ans<tot) ans=tot;
		return;
	}
	if(cnta<n/2){
		cnta++;
		dfs(now+1,tot+p[now].x);
		cnta--;
	}
	if(cntb<n/2){
		cntb++;
		dfs(now+1,tot+p[now].y);
		cntb--;
	}
	if(cntc<n/2){
		cntc++;
		dfs(now+1,tot+p[now].z);
		cntc--;
	}
}
int solve(){
	ans=0,cnta=0,cntb=0,cntc=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	if(n<=10){
		for(int i=1;i<=n;i++){
			p[i].x=a[i],p[i].y=b[i],p[i].z=c[i];
			p[i].id=i;
		}
		dfs(1,0);
		printf("%d\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int maxx=getmax(i);
		if(maxx==a[i]){
			if(cnta>=n/2){
				int idx=q.top().second.first,sz=q.top().second.second;
				int num=0;
				if(sz==1) num=getmid(idx);
				else num=getmin(idx);
				if(ans-q.top().first+num+maxx>ans){
					ans=ans-q.top().first+num+maxx;
					if(q.top().first==a[idx]) cnta--;
					else if(q.top().first==b[idx]) cntb--;
					else cntc--;
					q.pop();
					q.push({num,{idx,min(sz+1,3)}});
					q.push({maxx,{i,1}});
					cnta++;
					if(num==a[idx]) cnta++;
					else if(num==b[idx]) cntb++;
					else cntc++;
				}
			}
			else{
				q.push({maxx,{i,1}});
				ans+=maxx;
				cnta++;
			}
		}
		else if(maxx==b[i]){
			if(cntb>=n/2){
				int idx=q.top().second.first,sz=q.top().second.second;
				int num=0;
				if(sz==1) num=getmid(idx);
				else num=getmin(idx);
				if(ans-q.top().first+num+maxx>ans){
					ans=ans-q.top().first+num+maxx;
					if(q.top().first==a[idx]) cnta--;
					else if(q.top().first==b[idx]) cntb--;
					else cntc--;
					q.pop();
					q.push({num,{idx,min(sz+1,3)}});
					q.push({maxx,{i,1}});
					cntb++;
					if(num==a[idx]) cnta++;
					else if(num==b[idx]) cntb++;
					else cntc++;
				}
			}
			else{
				q.push({maxx,{i,1}});
				ans+=maxx;
				cntb++;
			}
		}
		else if(maxx==c[i]){
			if(cntc>=n/2){
				int idx=q.top().second.first,sz=q.top().second.second;
				int num=0;
				if(sz==1) num=getmid(idx);
				else num=getmin(idx);
				if(ans-q.top().first+num+maxx>ans){
					ans=ans-q.top().first+num+maxx;
					if(q.top().first==a[idx]) cnta--;
					else if(q.top().first==b[idx]) cntb--;
					else cntc--;
					q.pop();
					q.push({num,{idx,min(sz+1,3)}});
					q.push({maxx,{i,1}});
					cntc++;
					if(num==a[idx]) cnta++;
					else if(num==b[idx]) cntb++;
					else cntc++;
				}
			}
			else{
				q.push({maxx,{i,1}});
				ans+=maxx;
				cntc++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
