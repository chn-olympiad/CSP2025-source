#include<bits/stdc++.h>
#define ll long long
#define gc getchar
using namespace std;
const int N=100010;
void in(int &x){
	x=0;char c;
	while((c=gc())<'0'||c>'9');
	while(c>='0'&&c<='9')x=x*10+(c^48),c=gc();
}
int n,ans;
int a[N][4],b[N][4],c[N][3];
int cnt[4];
bool f[N];
struct n1{
	int v,id;
	bool operator < (const n1 x)const{
		return c[id][1]<c[x.id][1];
	}
};
priority_queue<n1>q1[4];
struct n2{
	int v,id;
	bool operator < (const n2 x)const{
		return c[id][2]<c[x.id][2];
	}
};
priority_queue<n2>q2[4];
int mian(){
	in(n);ans=0;
	for(int i=1;i<=n;++i){
		f[i]=0;
		for(int j=1;j<=3;++j)
			in(a[i][j]);
		if(a[i][1]>=a[i][2]){
			if(a[i][1]>=a[i][3]){
				b[i][1]=1;
				if(a[i][2]>=a[i][3])
					b[i][2]=2,b[i][3]=3;
				else
					b[i][2]=3,b[i][3]=2;
			}else{
				b[i][1]=3;
				b[i][2]=1;
				b[i][3]=2;
			}
		}else{
			if(a[i][1]>=a[i][3]){
				b[i][1]=2;
				b[i][2]=1;
				b[i][3]=3;
			}else{
				b[i][3]=1;
				if(a[i][2]>=a[i][3])
					b[i][1]=2,b[i][2]=3;
				else
					b[i][1]=3,b[i][2]=2;
			}
		}
		c[i][1]=a[i][b[i][1]]-a[i][b[i][2]];
		c[i][2]=a[i][b[i][2]]-a[i][b[i][3]];
	}
	// 1
	for(int i=1;i<=3;++i){
		cnt[i]=0;
		while(!q1[i].empty())
			q1[i].pop();
	}
	for(int i=1;i<=n;++i){
		q1[b[i][1]].push((n1){a[i][b[i][1]],i});
	}
	for(int i=1;i<=3;++i)
		while(!q1[i].empty()&&cnt[i]<n/2){
			n1 t=q1[i].top();q1[i].pop();
			++cnt[i];
			ans+=t.v;
			f[t.id]=true;
		}
	// 2
	for(int i=1;i<=3;++i)
		while(!q2[i].empty())
			q2[i].pop();
	for(int i=1;i<=n;++i){
		if(!f[i])
			q2[b[i][2]].push((n2){a[i][b[i][2]],i});
	}
	for(int i=1;i<=3;++i)
		while(!q2[i].empty()&&cnt[i]<n/2){
			n2 t=q2[i].top();q2[i].pop();
			++cnt[i];
			ans+=t.v;
			f[t.id]=true;
		}
	// 3
	for(int i=1;i<=n;++i)
		if(!f[i])
			ans+=a[i][b[i][3]];
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	for(in(T);T--;printf("%d\n",mian()));
	return 0;
}
