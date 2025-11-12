#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100100;
int n;
ll ans;
vector<int>g1,g2,g3;
struct node{
	int a[5];
}x[N];
int read(){
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
bool cmp(int a,int b){
	int suma=x[a].a[1]+x[a].a[2]+x[a].a[3];
	int sumb=x[b].a[1]+x[b].a[2]+x[b].a[3];
	int maxa=max(max(x[a].a[1],x[a].a[2]),x[a].a[3]);
	int maxb=max(max(x[b].a[1],x[b].a[2]),x[b].a[3]);
	int mina=min(min(x[a].a[1],x[a].a[2]),x[a].a[3]);
	int minb=min(min(x[b].a[1],x[b].a[2]),x[b].a[3]);
	return maxa-(suma-maxa-mina)<maxb-(sumb-maxb-minb);
}
void solve(vector<int>g){
	int s[N];
	int len=0;
	for(int i=0;i<g.size();i++){
		s[++len]=g[i];
	}
	sort(s+1,s+1+len,cmp);
	for(int i=1;i<=len-n/2;i++){
		int a=s[i]; 
		int suma=x[a].a[1]+x[a].a[2]+x[a].a[3];
		int maxa=max(max(x[a].a[1],x[a].a[2]),x[a].a[3]);
		int mina=min(min(x[a].a[1],x[a].a[2]),x[a].a[3]);
	//	cout<<maxa<<" "<<suma-maxa-mina<<"\n";
		ans=ans-maxa+(suma-maxa-mina);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--){
		g1.clear();
		g2.clear();
		g3.clear();
		n=read();
		ans=0;
		for(int i=1;i<=n;i++){
			x[i].a[1]=read();
			x[i].a[2]=read();
			x[i].a[3]=read();
			int maxx=max(max(x[i].a[1],x[i].a[2]),x[i].a[3]);
			if(maxx==x[i].a[1]){
				g1.push_back(i);
			}
			else if(maxx==x[i].a[2]){
				g2.push_back(i);
			}
			else{
				g3.push_back(i);
			}
			ans+=maxx;
		}
	//	cout<<"siz "<<g1.size()<<" "<<g2.size()<<" "<<g3.size()<<"\n";
		if(g1.size()>n/2){
			solve(g1);
		}
		if(g2.size()>n/2){
			solve(g2);
		}
		if(g3.size()>n/2){
			solve(g3);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
