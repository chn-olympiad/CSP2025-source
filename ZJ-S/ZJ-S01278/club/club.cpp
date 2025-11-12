#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int T;
int n;
struct node{
	ll a,b,c,z,u;
}s[N]; 
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
bool cmp3(node x,node y){
	return x.c>y.c;
}
priority_queue<int,vector<int> ,greater<int> > q;
ll f[35][35][35][35];
ll ma=0,sum=0;
ll dfs(int x,ll cnt,int a,int b,int c){
	if(cnt+ma*1ll*(n-x)<sum) return 0;
	if(f[a][b][c][x+1]) return cnt+f[a][b][c][x];
	ll t=0;
	if(x==n){
		return f[a][b][c][x]=cnt;
	}
	if(a<n/2&&s[x+1].a!=0)
		t=max(t,dfs(x+1,cnt+s[x+1].a,a+1,b,c));
	if(b<n/2&&s[x+1].b!=0)
		t=max(t,dfs(x+1,cnt+s[x+1].b,a,b+1,c));
	if(c<n/2&&s[x+1].c!=0)
		t=max(t,dfs(x+1,cnt+s[x+1].c,a,b,c+1));
	return f[a][b][c][x]=t;
}
bool cmp(node x,node y){
	return x.z>y.z;
}
bool cmpp(node x,node y){
	return x.u>y.u;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ma=-1;sum=0;
		bool flag=1,f=1,fl=1;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0) flag=0;
			if(s[i].c!=0) f=0;
			if(s[i].a!=0) fl=0;	
			s[i].z=s[i].a-s[i].c;
			s[i].u=s[i].c-s[i].a;
			ma=max(ma,max(s[i].a,max(s[i].b,s[i].c)));
		}
		if(flag&&f){
			sort(s+1,s+n+1,cmp1);
			for(int i=1;i<=n/2;i++) sum+=s[i].a;
			cout<<sum<<endl;
		}
		else if(f&&fl){
			sort(s+1,s+n+1,cmp2);
			for(int i=1;i<=n/2;i++) sum+=s[i].b;
			cout<<sum<<endl;
		}
		else if(flag&&fl){
			sort(s+1,s+n+1,cmp3);
			for(int i=1;i<=n/2;i++) sum+=s[i].c;
			cout<<sum<<endl;
		}
		else if(flag){
			int a=0,c=0;
			for(int i=1;i<=n;i++){
				if(s[i].a>s[i].c) a++;	
				else c++;
			}
			if(a>c){
				sort(s+1,s+n+1,cmp);
				for(int i=1;i<=n;i++){
					if(i<=n/2) sum+=s[i].a;
					else sum+=s[i].c;
				}
			}
			else if(a==c){
				for(int i=1;i<=n;i++){
					if(s[i].a>s[i].c) sum+=s[i].a;
					else sum+=s[i].c;
				}
			}
			else{
				sort(s+1,s+n+1,cmpp);
				for(int i=1;i<=n;i++){
					if(i<=n/2) sum+=s[i].c;
					else sum+=s[i].a;
				}
			}
			cout<<sum<<endl;
		}
		else{
			if(n<=30){
				sum=max(sum,dfs(1,s[1].a,1,0,0));
				sum=max(sum,dfs(1,s[1].b,0,1,0));
				sum=max(sum,dfs(1,s[1].c,0,0,1));
				cout<<sum<<endl;
			}
			else{
				for(int i=1;i<=n;i++){
					sum+=max(s[i].a,max(s[i].b,s[i].c));
				}
				cout<<sum<<endl;
			}
		}
	}
	return 0;
} 
