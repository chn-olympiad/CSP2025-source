#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pr pair<long long,long long>
#define forr(i,n) for(long long i=1;(i)<=(n);i++)
#define fo(i,n) for(long long i=0;(i)<(n);i++)
#define gc getchar
#define pc putchar
ll num,numm[110],f,cnt;
char cc;
ll n,m,k,c[15],u,v,w,s[15][10010],ff,vis[110],ans;
pr x;
vector<pr> a[10010];
priority_queue<pr,vector<pr>,greater<pr>> q;
//万分感谢stl_queue.h(优先忘了又得少几分)(虽然只会打模板最短路(也可能是生成树?)16分)
ll in(){
	f=1,num=0,cc=gc();
	for(;cc>'9'||cc<'0';cc=gc())
		if(cc=='-')
			f=-1;
	for(;cc<='9'&&cc>='0';cc=gc())
		num=num*10+cc-'0';
	return num*f;
}
void out(ll x){
	cnt=0,f=1;
	if(x==0)
		pc('0');
	else{
		if(x<0)
			x=-x,f=-1;
		while(x)
			numm[++cnt]=x%10,x/=10;
		for(ll i=cnt;i>=1;i--)
			pc(numm[i]+'0');
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),	m=in(),k=in();
	forr(i,m){
		u=in(),v=in(),w=in();
		a[u].push_back({w,v});
		a[v].push_back({w,u});
	}
	ff=1;
	forr(i,k){
		c[i]=in();
		if(c[i]!=0)
			ff=0;
		forr(j,n)
			s[i][j]=in();
	}
	if(k==0){
		vis[1]++;
		fo(i,a[1].size())
			q.push(a[1][i]);
		while(!q.empty()){
			x=q.top();
			q.pop();
			if(!vis[x.second]){
			vis[x.second]++;
			ans+=x.first;
			fo(i,a[x.second].size()){
				if(!vis[a[x.second][i].second]){
					q.push(a[x.second][i]);
				}
			}
			}
		}
	}
	out(ans);
	return 0;
}