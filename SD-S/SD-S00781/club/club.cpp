#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
//#define int long long
#define re register
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){x=-x;putchar('-');}if(x<=9){putchar(x+'0');return;}write(x/10);putchar(x%10+'0');}
const int N=1e5+5;
int t,n,ans=0,tag[N];
priority_queue<int> pq;
struct f{
	int x,y,z;
}a[N];
void dfs(int st,int cnt1,int cnt2,int cnt3,int sum){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return;
	if(sum+tag[n]-tag[st-1]<=ans) return;
	if(st==n+1){
		ans=max(ans,sum);
	}
	if(a[st].x) dfs(st+1,cnt1+1,cnt2,cnt3,sum+a[st].x);
	if(a[st].y) dfs(st+1,cnt1,cnt2+1,cnt3,sum+a[st].y);
	if(a[st].z) dfs(st+1,cnt1,cnt2,cnt3+1,sum+a[st].z);
}
bool cmp(f a,f b){
	return a.x>b.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		ans=0;
		int ccnt1=0,ccnt2=0;
		for(re int i=1;i<=n;++i){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			ccnt1+=a[i].y,ccnt2+=a[i].z;
			tag[i]=tag[i-1]+max(a[i].x,max(a[i].y,a[i].z));
		}
		if(ccnt1+ccnt2==0){
			sort(a+1,a+1+n,cmp);
			for(re int i=1;i<=n/2;i++) ans+=a[i].x;
		}else if(ccnt2==0){
			while(!pq.empty()) pq.pop();
			sort(a+1,a+1+n,cmp);
			for(re int i=1;i<=n/2;++i){
				pq.push(a[i].y-a[i].x);
				ans+=a[i].x;
			}
			for(re int i=n/2+1;i<=n;++i){
				int xx=pq.top();
				if(xx+a[i].x>a[i].y){
					ans+=xx+a[i].x;
					pq.pop();
					pq.push(a[i].y-a[i].x);
				}else{
					ans+=a[i].y;
				}
			}
		}else{
			dfs(1,0,0,0,0);
		}
		write(ans);
		printf("\n");
	}
	return 0;
}
//10 9 8
//9  0 0
//5  0 0
//4  1 3
