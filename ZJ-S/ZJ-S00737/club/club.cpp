#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define maxn 100010
#define inf 2147483647
using namespace std;
int n,tmp,ans,vis[maxn];
int num[5];
struct node{
	int i,clas,val;
	operator<(const node&a)const{return a.val>val;}
};
priority_queue<node> qwq;
struct edon{
	int i,clas,val;
	operator<(const edon&a)const{return (a.clas==1?(clas==1?a.val>val:1):(clas==1?0:a.val>val));}
};
priority_queue<edon> qa,qb,qc;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
void write(int x){print(x);putchar('\n');}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();ans=-inf;
		for(int i=1;i<=n;++i){
			vis[i]=0;
			int a=read(),b=read(),c=read();
			qwq.push({i,1,a});qwq.push({i,2,b});qwq.push({i,3,c});
			qa.push({i,1,a});qa.push({i,2,b});qa.push({i,3,c});
			qb.push({i,2,a});qb.push({i,1,b});qb.push({i,3,c});
			qc.push({i,3,a});qc.push({i,2,b});qc.push({i,1,c});
		}
		num[1]=num[2]=num[3]=0;tmp=0;
		while(qwq.size()){
			node u=qwq.top();qwq.pop();
			int i=u.i,clas=u.clas,w=u.val;
			if(vis[i]||num[clas]+1>n/2)continue;
			tmp+=w,vis[i]=1,num[clas]++;
		}
		ans=max(ans,tmp);
		for(int i=1;i<=n;++i)vis[i]=0;
		num[1]=num[2]=num[3]=0;tmp=0;
		while(qa.size()){
			edon u=qa.top();qa.pop();
			int i=u.i,clas=u.clas,w=u.val;
			if(vis[i]||num[clas]+1>n/2)continue;
			tmp+=w,vis[i]=1,num[clas]++;
		}
		ans=max(ans,tmp);
		for(int i=1;i<=n;++i)vis[i]=0;
		num[1]=num[2]=num[3]=0;tmp=0;
		while(qb.size()){
			edon u=qb.top();qb.pop();
			int i=u.i,clas=u.clas,w=u.val;
			if(vis[i]||num[clas]+1>n/2)continue;
			tmp+=w,vis[i]=1,num[clas]++;
		}
		ans=max(ans,tmp);
		for(int i=1;i<=n;++i)vis[i]=0;
		num[1]=num[2]=num[3]=0;tmp=0;
		while(qc.size()){
			edon u=qc.top();qc.pop();
			int i=u.i,clas=u.clas,w=u.val;
			if(vis[i]||num[clas]+1>n/2)continue;
			tmp+=w,vis[i]=1,num[clas]++;
		}
		ans=max(ans,tmp);
		write(ans);
	}
	return 0;
}
