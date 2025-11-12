#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int read(){
	int x=0,f=1;
	char c=getchar();
	for(;c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,a[N][5],ret=0;
vector<int>v[5];
priority_queue<int,vector<int>,greater<int> >q;
void sol(int op){
	for(auto x:v[op]){
		int mi=1e5;
		for(int j=1;j<=3;j++){
			if(j==op)continue;
			mi=min(mi,a[x][op]-a[x][j]);
		}
		q.push(mi);
	}
	int cnt=v[op].size()-n/2;
	while(cnt){
		int x=q.top();q.pop();
		ret-=x;
		cnt--;
	}
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	_=read();
	while(_--){
		n=read();
		for(int i=1;i<=n;i++){
			int mx=0;
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				mx=max(mx,a[i][j]);
			}
			if(mx==a[i][1]){
				v[1].push_back(i);
			}else if(mx==a[i][2])v[2].push_back(i);
			else v[3].push_back(i);
			ret+=mx;
		}
		if(v[1].size()>n/2){
			sol(1);
		}else if(v[2].size()>n/2){
			sol(2);
		}else if(v[3].size()>n/2){
			sol(3);
		}
		printf("%lld\n",ret);
		ret=0;
		v[1].clear();v[2].clear();v[3].clear();
		while(!q.empty())q.pop();
	}
	return 0;
}
