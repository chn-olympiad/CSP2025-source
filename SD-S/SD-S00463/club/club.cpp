#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
long long sum;
struct member{
	int a,b,c;
}m[N];
bool cmp1(member a,member b){
	return a.a>b.a;
}
bool cmp2(member a,member b){
	return a.b>b.b;
}
int ce[N];
void dfs(int p,long long cnt,int sa,int sb,int sc){
	if(p>n){
		sum=max(sum,cnt);
		return;
	}
	if(sa+1<=n/2)	dfs(p+1,m[p].a+cnt,sa+1,sb,sc);
	if(sb+1<=n/2)	dfs(p+1,m[p].b+cnt,sa,sb+1,sc);
	if(sc+1<=n/2)	dfs(p+1,m[p].c+cnt,sa,sb,sc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		bool f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].b!=0||m[i].c!=0){
				f1=0;
			}
			if(m[i].c!=0){
				f2=0;
			}
		}
		if(f1){
			sort(m+1,m+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				sum+=m[i].a;
			}
			cout<<sum<<'\n';
			continue;
		}
		else if(f2){
			sort(m+1,m+1+n,cmp1);
			long long sum1=0,sum2=0;
			for(int i=1;i<=n/2;i++){
				sum1+=m[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				sum1+=m[i].b;
			}
			
			sort(m+1,m+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				sum2+=m[i].b;
			}
			for(int i=n/2+1;i<=n;i++){
				sum2+=m[i].a;
			}
			
			sum=max(sum1,sum2);
			cout<<sum<<'\n';
		}
		else{
			dfs(1,0,0,0,0);
			cout<<sum<<'\n';
		}
	}
	return 0;
}
