#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int res=0,f=1;char ch=getchar();
	for(;ch>57||ch<48;ch=getchar())if(ch=='-')f=-1;
	for(;ch>47&&ch<58;ch=getchar())res=(res<<1)+(res<<3)+(ch^48);
	return res*f;
}
struct node{
	int a;
	int b;
	int c;
	int id;
	bool operator < (const node &x)const{
		if(a-b==x.a-x.b){
			return a-c<x.a-x.c;
		}
		return a-b<x.a-x.b;
	}
}a[200005];
struct nod{
	int a;
	int id;
	int num;
	bool operator <(const nod &x)const{
		return a>x.a;
	}
};
bool vis[200005],fl[2];
int nex[200005],pre[200005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int T=read();T--;){
		priority_queue<node>q;
		priority_queue<nod>q2;
		int n=read(),ans=0,sum=0;
		fl[1]=fl[2]=0;
		int cnt=n/2,cnt2=n;
		for(int i=1;i<=n;i++)
			a[i]={read(),read(),read(),i},q.push(a[i]);
		sort(a+1,a+1+n);
		while(cnt--){
			q2.push({q.top().a-q.top().c,1,q.top().id});
			ans+=q.top().a;
			q.pop();
		}
		while(!q.empty()){
			q2.push({q.top().b-q.top().c,0,q.top().id});
			ans+=q.top().b;
			q.pop();
		}
		for(int i=0;i<=n;i++)nex[i]=i+1,pre[i]=i-1;
		cnt=n/2;
		while(q2.size()){
			if(sum==n/2)break;
			nod t=q2.top();
			q2.pop();
//			cout<<t.a<<' '<<t.num<<'\n';
			if(t.a<0){
				int num=t.num;
				ans=ans-t.a;
				sum++;
				nex[pre[num]]=nex[num];
				pre[nex[num]]=pre[num];
				if(num==cnt){
					if(t.id)cnt=nex[cnt];
					else cnt=pre[cnt];
				}
			}
			int p[]={-a[cnt].a+a[cnt].b,a[nex[cnt]].a-a[nex[cnt]].b},num=-t.a-p[t.id];
			if(num<0){
				fl[t.id]=1;
				if(fl[1]&fl[0])break;
				continue;
			}
			if(t.id==1){
				if(p[1]>0&&cnt>n/2){
					ans+=num;
//					cout<<cnt<<'\n';
					nex[pre[cnt]]=nex[cnt];
					pre[nex[cnt]]=pre[cnt];
					cnt=nex[cnt];
				}
			}
			else {
				if(p[0]>0&&cnt<=n/2){
					ans+=num;
//					cout<<cnt<<'\n';
					nex[pre[cnt]]=nex[cnt];
					pre[nex[cnt]]=pre[cnt];
					cnt=pre[cnt];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
