#include<bits/stdc++.h>
using namespace std;
struct aa{
	long long i,t;
};
bool operator<(aa x,aa y){
	return x.t>y.t;
}
long long n,m,k,u,v,t,ss=114514191981000000ll,re[11],b[10011],C[11];
vector<aa>c[10011];
priority_queue<aa>q;
char ch;
void R(long long &i){
	for(ch=getchar();ch>'9'||ch<'0';ch=getchar());
	for(i=0;ch>='0'&&ch<='9';ch=getchar())i=i*10+ch-'0';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(;m;m--)R(u),R(v),R(t),c[u].push_back({v,t}),c[v].push_back({u,t});
	for(int i=1;i<=k;i++){
		R(C[i]);
		for(int j=1;j<=n;j++)R(t),c[i+n].push_back({j,t}),c[j].push_back({i+n,t});
	}
	for(int X=(1<<k)-1;X<=(1<<k)-1;X++){
		memset(b,0,sizeof b);
		long long s=0;
		for(int i=1;i<=k;i++)re[i]=!!((X>>(i-1))&1),s+=re[i]*C[i];
		while(!q.empty())q.pop();
		q.push({1,0});
		while(!q.empty()){
			aa x=q.top();
			q.pop();
			if(b[x.i])continue;
			b[x.i]=1;
			s+=x.t;
			for(int j=0;j<c[x.i].size();j++){
				if(!b[c[x.i][j].i]&&(c[x.i][j].i<=n||c[x.i][j].i>n&&re[c[x.i][j].i-n])){
					q.push(c[x.i][j]);
				}
			}
		}
		ss=min(ss,s);
	}
	cout<<ss;
	return 0;
}

