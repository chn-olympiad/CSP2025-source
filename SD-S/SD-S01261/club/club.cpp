#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define fir first
#define sec second
#define mkp make_pair
#define pii pair<int,int>
#define file(_1) freopen(_1".in","r",stdin),freopen(_1".out","w",stdout);
#define error(_) cerr<<_<<endl
#define look_memory cerr<<(&m1-&m2)/1024.0/1024.0<<"MB"<<endl;
#define look_time cerr<<(t2-t1)/1000.0<<"s"<<endl;
using namespace std;
template <typename T>
inline void read(T &x){
	T f=1,c=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		c=(c<<3)+(c<<1)+(ch^48);
		ch=getchar();
	}
	x=f*c;
}

template<typename T,typename ...Args>
inline void read(T &x,Args &...args){
	read(x),read(args...);
}
namespace white_carton{
	int n,a[100100][5],cnt[10],ans;
	pii maxn[100100],maxn2[100100];
	priority_queue<int,vector<int>,greater<int>> q;
	void solve(){
		while(!q.empty()){
			q.pop();
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		read(n);
		for(int i=1;i<=n;i++){
			maxn[i]=maxn2[i]={0,0};
			for(int j=1;j<=3;j++){
				read(a[i][j]);
				if(a[i][j]>maxn[i].fir){
					swap(maxn2[i],maxn[i]);
					maxn[i]=mkp(a[i][j],j);
				}
				else{
					if(a[i][j]>maxn2[i].fir){
						maxn2[i]=mkp(a[i][j],j);
					}
				}
			}
			cnt[maxn[i].sec]++;
			ans+=maxn[i].fir;
		}
		for(int j=1;j<=3;j++){
			if(cnt[j]>n/2){
				for(int i=1;i<=n;i++){
					if(maxn[i].sec==j){
						q.push(maxn[i].fir-maxn2[i].fir);
					}
				}
				break;
			}
		}
		int s=q.size();
		for(int i=n/2+1;i<=s;i++){
			ans-=q.top();
			q.pop();
		}
		cout<<ans<<endl;
	}
}
int T=1;
signed main(){
	file("club");
	read(T);
	while(T--){
		white_carton::solve();
	}
}
//1.快读
//2.注意空间
//3.多测清数据
//4.对拍
//5.打满暴力
//6.文件
//7. RP++;



//starback24

