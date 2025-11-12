#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
struct node{int x,y,z;}a[N];
struct edge{int x,idx;}b[5];
struct vd{int cnt,pl;}c[5];
int cnt[5],ans,n;

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48),ch=getchar();}
	return s*f;
}

inline int f(node x){
	return (x.x+x.y+x.z)+(abs(x.x+x.z-x.y)+abs(x.y+x.x-x.z)+abs(x.x+x.y-x.z));
}

inline bool operator < (node x,node y){
	return f(x)>f(y);
}

inline bool operator < (edge x,edge y){
	return x.x>y.x;
}

inline bool operator < (vd x,vd y){
	return x.cnt<y.cnt;
}

inline void dfs(int x,int cnt1,int cnt2,int cnt3,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<n/2) dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x].x);
	if(cnt2<n/2) dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x].y);
	if(cnt3<n/2) dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x].z);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;ans=0;cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++) a[i]={read(),read(),read()};
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}else{
			sort(a+1,a+n+1);
			for(int i=1;i<=n;i++){
				b[1]={a[i].x,1};
				b[2]={a[i].y,2};
				b[3]={a[i].z,3};
				sort(b+1,b+3+1);
				if(b[1].x>b[2].x){
					if(cnt[b[1].idx]<n/2) cnt[b[1].idx]++,ans+=b[1].x;
					else if(b[2].x>b[3].x){
						if(cnt[b[2].idx]<n/2) cnt[b[2].idx]++,ans+=b[2].x;
						else cnt[b[3].idx]++,ans+=b[3].x; 
					}else{
						int cnt1=cnt[b[2].idx],cnt2=cnt[b[3].idx];
						if(cnt1>cnt2) cnt[b[3].idx]++,ans+=b[3].x;
						else cnt[b[2].idx]++,ans+=b[2].x;
					}
				}else{
					if(b[2].x>b[3].x){
						int cnt1=cnt[b[1].idx],cnt2=cnt[b[2].idx];
						if(cnt1>cnt2) cnt[b[2].idx]++,ans+=b[2].x;
						else cnt[b[1].idx]++,ans+=b[1].x;
					}else{
						int cnt1=cnt[b[1].idx],cnt2=cnt[b[2].idx],cnt3=cnt[b[3].idx];
						c[1]={cnt1,b[1].idx};
						c[2]={cnt2,b[2].idx};
						c[3]={cnt3,b[3].idx};
						sort(c+1,c+3+1);
						cnt[c[1].pl]++,ans+=b[c[1].pl].x;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
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

50
*/