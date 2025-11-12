#include<bits/stdc++.h>

#define hyc_qcz_jmr_baoyouwo_AC
#define zty_AK_CSPS_2025

#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fep(i,s,e) for(int i=s;i<e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
#define pef(i,s,e) for(int i=s;i>e;i--)

namespace FastIO{
	template <typename T> inline void read(T &x){
		x=0;
		T f=1;
		T c=getchar();
		for(;!isdigit(c);c=getchar()){
			if(c=='-'){
				f=-1;
			}
		}
		for(;isdigit(c);c=getchar()){
			x=(x<<1)+(x<<3)+(c^48);
		}
		x*=f;
	}
	template <typename T> inline void print(T x){
		if(x<0){
			x=-x;
			putchar('-');
		}
		if(x>9){
			print(x/10);
		}
		putchar((x%10)^48);
	}
}

using namespace std;
using namespace FastIO;
struct nod{
	int num;
	int id;
};
struct node{
	nod a[5];
}p[100005];
int T,n,cnt[5],ans;
priority_queue<int,vector<int>,greater<int> >pq;
bool cmp(nod c,nod d){
	return c.num>d.num;
}
void work(int op){
	while(!pq.empty()){
		pq.pop();
	}
	rep(i,1,n){
		if(p[i].a[1].id==op){
			pq.push(p[i].a[1].num-p[i].a[2].num);
		}
	}
	while(cnt[op]>n/2){
		ans-=pq.top();
		pq.pop();
		cnt[op]--;
	}
}
void solve(){
	read(n);
	ans=cnt[1]=cnt[2]=cnt[3]=0;
	rep(i,1,n){
		rep(j,1,3){
			read(p[i].a[j].num);
			p[i].a[j].id=j;
		}
		sort(p[i].a+1,p[i].a+4,cmp);
		cnt[p[i].a[1].id]++;
		ans+=p[i].a[1].num;
	}
	if(cnt[1]>n/2){
		work(1);
	}
	else if(cnt[2]>n/2){
		work(2);
	}
	else if(cnt[3]>n/2){
		work(3);
	}
	print(ans);
	putchar('\n');
}
int main(){
	hyc_qcz_jmr_baoyouwo_AC
	zty_AK_CSPS_2025
//	freopen("club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	rep(i,1,T){
		solve();
	}
	return 0;	
}