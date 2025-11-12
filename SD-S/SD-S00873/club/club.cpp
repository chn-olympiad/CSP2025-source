#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define mp make_pair
//#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
int n,bf[N],ans,maxn;
bool vis[N];
struct stu{
	int idx,ai[4],rk[4];
}a[N];
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
inline bool check(){
	for(int i=1;i<=n;i++){
		if(!(a[i].ai[2]==0&&a[i].ai[3]==0)) return false;
	}
	return true;
}
inline bool ck2(){
	for(int i=1;i<=n;i++){
		if(a[i].ai[3]!=0) return false;
	}
	return true;
}
void dfs(int x,int res,int t1,int t2,int t3,int maxn){
	if(t1+t2+t3>2*maxn) return;
	if(t1>maxn) return;
	if(t2>maxn) return;
	if(t3>maxn) return;
	if(x==n+1){
		ans=max(ans,res);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			dfs(x+1,res+a[x].ai[i],t1++,t2,t3,maxn);
			cout<<t1<<" ";
		}
		else if(i==2){
			dfs(x+1,res+a[x].ai[i],t1,t2++,t3,maxn);
		}
		else{
			dfs(x+1,res+a[x].ai[i],t1,t2,t3++,maxn);
		}
	}
}
inline bool cmpp(int x,int y){return x>y;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		maxn=n/2;
		n=read();
		for(int i=1;i<=n;i++){
			a[i].idx=i;
			for(int j=1;j<=3;j++) a[i].ai[j]=read();
		}
		if(check()){
			for(int i=1;i<=n;i++) bf[i]=a[i].ai[1];
			sort(bf+1,bf+1+n,cmpp);
			ans=0;
			for(int i=1;i<=n/2;i++) ans+=bf[i];
			cout<<ans<<"\n";
			continue;
		}
		else{
			ans=0;
			dfs(1,0,0,0,0,maxn);
			cout<<ans<<"\n";
		}
//		priority_queue<pii> q1,q2,q3;//ai,idx
//		for(int i=1;i<=n;i++){
//			q1.push(mp(a[i].ai[1],i));
//			q2.push(mp(a[i].ai[2],i));
//			q3.push(mp(a[i].ai[3],i));
//		}
//		int tt1=0,tt2=0,tt3=0;
//		bool f1=true,f2=true,f3=true;
//		int ans=0;
//		if(ck2()) f3=false;
//		while(1){
//			pii t1,t2,t3;
//			if(tt1+tt2+tt3>n) break;
//			if(tt1<=n/2){
//				t1=q1.top();
//				if(vis[t1.second]){
//					bool flag=true;
//					while(!q1.empty()){
//						t1=q1.top();
//						if(!vis[t1.second]){
//							flag=false;
//							break;
//						}
//					}
//					if(flag){
//						f1=false;
//						tt1=n/2+1;continue;
//					}
//				}
//			}
//			if(tt2<=n/2){
//				t2=q2.top();
//				if(vis[t2.second]){
//					bool flag=true;
//					while(!q2.empty()){
//						t2=q2.top();
//						if(!vis[t2.second]){
//							flag=false;
//							break;
//						}
//					}
//					if(flag){
//						f2=false;
//						tt2=n/2+1;continue;
//					}
//				}
//			}
//			if(tt3<=n/2&&f3){
//				t3=q3.top();
//				if(vis[t3.second]){
//					bool flag=true;
//					while(!q3.empty()){
//						t3=q3.top();
//						if(!vis[t3.second]){
//							flag=false;
//							break;
//						}
//					}
//					if(flag){
//						f3=false;
//						tt3=n/2+1;continue;
//					}
//				}
//			}
//			if(f1&&f2&&f3){
//				
//			}
//			else if(f1&&f2){
//				if(t1.second!=t2.second){
//					ans+=t1.first+t2.first;
//					vis[t1.second]=vis[t2.second]=true;
//					tt1++,tt2++;
//					q1.pop(),q2.pop();
//				}
//				else{
//					q1.pop(),q2.pop();
//					pii t3=q1.top(),t4=q2.top();
//					if(t1.first-t3.first>t2.first-t4.first){
//						q2.push(t2);
//						ans+=t1.first;tt1++;vis[t1.second]=true;
//					}
//					else{
//						q1.push(t1);
//						ans+=t2.first;tt2++;vis[t2.second]=true;
//					}
//				}
//			}
//			else if(f1&&f3){
//				
//			}
//			else if(f2&&f3){
//				
//			}
//			else if(f1){
//				
//			}
//			else if(f2){
//				
//			}
//			else if(f3){
//				
//			}
//		}
	}
	return 0;
}

