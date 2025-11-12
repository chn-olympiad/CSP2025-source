#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
struct Node{
	ll a,b,c,mx;
}d[100010];
struct S{
	ll x,y;
};
ll as=0;
int c1,c2,c3;
int e1[100010],e2[100010],e3[100010];
void dfs(int dep,int num1,int num2,int num3,ll sum){
	if(dep==n+1){
		as=max(as,sum);
		return ;
	}
	if(num1<n/2){
		dfs(dep+1,num1+1,num2,num3,sum+d[dep].a);
	}
	if(num2<n/2){
		dfs(dep+1,num1,num2+1,num3,sum+d[dep].b);
	}
	if(num3<n/2){
		dfs(dep+1,num1,num2,num3+1,sum+d[dep].c);
	}
}
bool cmp1(Node x,Node y){
	return x.mx>y.mx;
}
bool cmp(Node x,Node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=1;
		bool g=1;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			d[i].mx=max(d[i].a,max(d[i].b,d[i].c));
			flag&=(d[i].b==d[i].c&&d[i].c==0);
			g&=(d[i].c==0);
		}
		if(n<=10){
			as=0;
			dfs(1,0,0,0,0);	
			cout<<as<<'\n';		
		}else if(flag){
			sort(d+1,d+1+n,cmp);
			ll sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=d[i].a;
			}
			cout<<sum<<'\n';
		}else{
			priority_queue<int> q1,q2,q3,q4,q5,q6;
			sort(d+1,d+1+n,cmp1);
			ll ans=0;
			bool v1[100010],v2[100010],v3[100010];
			for(int i=1;i<=n;i++){
				if(d[i].mx==d[i].a){
					if(c1<n/2){
						e1[++c1]=i;
						ans+=d[i].a;
					}else{
						int mx=0,rd,dd;
						for(int j=1;j<=c1;j++){
							if(c2<n/2){
								if(mx<d[j].b+d[i].a-d[j].a&&!v2[j]){
									mx=d[j].b+d[i].a-d[j].a;
									rd=j;
									dd=2;
								}
							}
							if(c3<n/2){
								if(mx<d[j].c+d[i].a-d[j].a&&!v3[j]){
									mx=d[j].c+d[i].a-d[j].a;
									dd=3;
								}
							}
						}
						ans+=mx;
					}
				}else if(d[i].mx==d[i].b){
					if(c2<n/2){
						e2[++c2]=i;
						ans+=d[i].b;
					}else{
						int mx=0;
						for(int j=1;j<=c1;j++){
							if(c1<n/2){
								if(mx<d[j].a+d[i].b-d[j].b&&!v1[j]){
									mx=d[j].a+d[i].b-d[j].b;
								}
							}
							if(c3<n/2){
								if(mx<d[j].c+d[i].b-d[j].b&&!v3[j]){
									mx=d[j].c+d[i].b-d[j].b;
								}
							}
						}
						ans+=mx;
					}
				}else if(d[i].mx==d[i].c){
					if(c3<n/2){
						e3[++c3]=i;
						ans+=d[i].c;
					}else{
						int mx=0;
						for(int j=1;j<=c1;j++){
							if(c1<n/2){
								if(mx<d[j].a+d[i].c-d[j].c&&!v1[j]){
									mx=d[j].a+d[i].c-d[j].c;
								}
							}
							if(c2<n/2){
								if(mx<d[j].b+d[i].c-d[j].c&&!v2[j]){
									mx=d[j].b+d[i].c-d[j].c;
								}
							}
						}
						ans+=mx;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
