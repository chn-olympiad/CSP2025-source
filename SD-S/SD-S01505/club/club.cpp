#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<random>
#define r read()
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
const int N=1e5+10;
int T,n,a[N][5];
long long ans;
int s[5];
int id[15];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >c1;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >c2;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >c3;
struct Node{
	int x1,x2,x3;
}b[N];
long long calc(){
	long long res=0;
	long long cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(id[i]==1){
			++cnt1;
			res+=a[i][id[i]];
			if(cnt1>(n>>1))return -1;
		}
		else if(id[i]==2){
			++cnt2;
			res+=a[i][id[i]];
			if(cnt2>(n>>1))return -1;
		}
		else if(id[i]==3){
			++cnt3;
			res+=a[i][id[i]];
			if(cnt3>(n>>1))return -1;
		}
	}
	return res;
}
void dfs(int cur){
	if(cur==n){
		ans=max(ans,calc());
		return ;
	}
	for(int i=1;i<=3;i++){
		id[cur+1]=i;
		dfs(cur+1);
	}
}
void make_b(){
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])b[i]={1,2,3};
		if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])b[i]={1,3,2};
		if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])b[i]={2,1,3};
		if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])b[i]={2,3,1};
		if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])b[i]={3,1,2};
		if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1])b[i]={3,2,1};
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=r;
	while(T--){
		n=r;
		ans=0;
		for(int i=1;i<=n;i++)a[i][1]=r,a[i][2]=r,a[i][3]=r;
		if(n<=10){
			dfs(0);
			printf("%lld\n",ans);
		}
		else{
			make_b();
			s[1]=s[2]=s[3]=0;
			while(!c1.empty()) c1.pop();
			while(!c2.empty()) c2.pop();
			while(!c3.empty()) c3.pop();
			for(int i=1;i<=n;i++){
				int loc=b[i].x1;
				ans+=a[i][loc];++s[loc];
				if(loc==1){
					c1.push(make_pair(a[i][loc]-a[i][b[i].x2],i));
					if(s[loc]>(n>>1)){
						--s[loc];
						pair<int,int> k=c1.top();
						c1.pop();
						int x=k.second;
						++s[b[x].x2];
						ans-=a[x][b[x].x1];
						ans+=a[x][b[x].x2];
						if(b[x].x1==2) c2.push(make_pair(a[x][b[x].x2]-a[x][b[x].x3],x));
						else if(b[x].x1==3) c3.push(make_pair(a[x][b[x].x2]-a[x][b[x].x3],x));
					}
				}
				else if(loc==2){
					c2.push(make_pair(a[i][loc]-a[i][b[i].x2],i));
					if(s[loc]>(n>>1)){
						--s[loc];
						pair<int,int> k=c2.top();
						c2.pop();
						int x=k.second;
						++s[b[x].x2];
						ans-=a[x][b[x].x1];
						ans+=a[x][b[x].x2];
						if(b[x].x1==1) c1.push(make_pair(a[x][b[x].x2]-a[x][b[x].x3],x));
						else if(b[x].x1==3) c3.push(make_pair(a[x][b[x].x2]-a[x][b[x].x3],x));
					}
				}
				else if(loc==3){
					c3.push(make_pair(a[i][loc]-a[i][b[i].x2],i));
					if(s[loc]>(n>>1)){
						--s[loc];
						pair<int,int> k=c3.top();
						c3.pop();
						int x=k.second;
						++s[b[x].x2];
						ans-=a[x][b[x].x1];
						ans+=a[x][b[x].x2];
						if(b[x].x1==1) c1.push(make_pair(a[x][b[x].x2]-a[x][b[x].x3],x));
						else if(b[x].x1==2) c2.push(make_pair(a[x][b[x].x2]-a[x][b[x].x3],x));
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
