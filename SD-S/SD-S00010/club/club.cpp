#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct node{
	int a,b,c,xa,xb,xc;
}s[N];
struct Node{
	int x,y,idx;
}v[N];
inline bool cmp(Node a,Node b){
	return max(a.x,a.y)<max(b.x,b.y);
}
bool vis[N][3];
vector<int> x,y,z;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		memset(vis,true,sizeof(vis));
		int ans=0;
		int n=read();
		x.clear(),y.clear(),z.clear();
		for(int i=1;i<=n;i++){
			s[i].a=read(),s[i].b=read(),s[i].c=read();
			s[i].xa=abs(s[i].a-s[i].b);
			s[i].xb=abs(s[i].b-s[i].c);
			s[i].xc=abs(s[i].c-s[i].a);
		}
		for(int i=1;i<=n;i++){
			int maxx=max(max(s[i].a,s[i].b),s[i].c);
			if(maxx==s[i].a)
				x.push_back(i);
			else if(maxx==s[i].b)
				y.push_back(i);
			else
				z.push_back(i);
		}
		int len1=x.size();
		int len2=y.size();
		int len3=z.size();
		int k=n/2;
		if(len1>k){
			for(int i=0;i<len1;i++)
				v[i].x=s[x[i]].xa,v[i].y=s[x[i]].xc,v[i].idx=x[i];
			sort(v,v+len1,cmp);
			int j=0;
			while(len1>k){
				if(len3<k && v[j].x>v[j].y){
					len3++;
					len1--;
					z.push_back(v[j].idx);
					vis[v[j].idx][0]=false;
				}
				else if(len2<k && v[j].x<v[j].y){
					len2++;
					len1--;
					y.push_back(v[j].idx);
					vis[v[j].idx][0]=false;
				}
				j++;
			}
		}
		if(len2>k){
			for(int i=0;i<len2;i++)
				v[i].x=s[y[i]].xa,v[i].y=s[y[i]].xb,v[i].idx=y[i];
			sort(v,v+len2,cmp);
			int j=0;
			while(len2>k){
				if(len3<k && v[j].x>=v[j].y){
					len3++;
					len2--;
					z.push_back(v[j].idx);
					vis[v[j].idx][1]=false;
				}
				else if(len1<k && v[j].x<v[j].y){
					len1++;
					len2--;
					x.push_back(v[j].idx);
					vis[v[j].idx][1]=false;
				}
				j++;
			}
		}
		if(len3>k){
			for(int i=0;i<len3;i++)
				v[i].x=s[y[i]].xb,v[i].y=s[y[i]].xc,v[i].idx=y[i];
			sort(v,v+len3,cmp);
			int j=0;
			while(len3>k){
				if(len1<k && v[j].x>v[j].y){
					len1++;
					len3--;
					x.push_back(v[j].idx);
					vis[v[j].idx][2]=false;
				}
				else if(len2<k && v[j].x<v[j].y){
					len2++;
					len3--;
					y.push_back(v[j].idx);
					vis[v[j].idx][2]=false;
				}
				j++;
			}
		}
		for(int i=0;i<x.size();i++)
			if(vis[x[i]][0])
				ans+=s[x[i]].a;
		for(int i=0;i<y.size();i++)
			if(vis[y[i]][1])
				ans+=s[y[i]].b;
		for(int i=0;i<z.size();i++)
			if(vis[z[i]][2])
				ans+=s[z[i]].c;
		printf("%lld\n",ans);
	}
	return 0;
}

