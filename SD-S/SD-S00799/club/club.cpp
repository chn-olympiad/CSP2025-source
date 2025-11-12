#include<algorithm>
#include<iostream>
using namespace std;
struct p{
	int a,b,c;
}s[100100];
int n,mx=-1,sum;
void dfs(int t,int s1,int s2,int s3,int s4){
	if(t==n){
		mx=max(mx,s4);
		return;
	}
	if(s1+1<=n/2)dfs(t+1,s1+1,s2,s3,s4+s[t+1].a);
	if(s2+1<=n/2)dfs(t+1,s1,s2+1,s3,s4+s[t+1].b);
	if(s3+1<=n/2)dfs(t+1,s1,s2,s3+1,s4+s[t+1].c);
}
bool cmp(p a,p b){return a.a>b.b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		mx=-1,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].b>>s[i].c;
		if(n<=30){
			dfs(0,0,0,0,0);
			cout<<mx<<endl;
			continue;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n/2;i++)sum+=s[i].a;
		for(int i=n/2+1;i<=n;i++)sum+=s[i].b;
		cout<<sum<<endl;
	}
	return 0;
}
