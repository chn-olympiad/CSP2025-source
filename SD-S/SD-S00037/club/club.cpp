#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxx=0,ans=0,an[5];
int n;
struct node{
	int e1,e2,e3;
	int d1,d2,d3;
	int bi,md,mi;
}a[100004];
bool cmp(node a,node b){
	if(a.d1==b.d1){
		if(a.d2==b.d2){
			return a.d3>b.d3;
		}
		return a.d2>b.d2;
	}
	return a.d1>b.d1;
}
void dfs(int deep){
	if(deep==n+1){
		maxx=max(maxx,ans);
		return ;
	}
	if(an[1]+1<=(n>>1)){
		an[1]++;
		ans+=a[deep].e1;
		dfs(deep+1);
		an[1]--;
		ans-=a[deep].e1;
	}
	if(an[2]+1<=(n>>1)){
		an[2]++;
		ans+=a[deep].e2;
		dfs(deep+1);
		an[2]--;
		ans-=a[deep].e2;
	}
	if(an[3]+1<=(n>>1)){
		an[3]++;
		ans+=a[deep].e3;
		dfs(deep+1);
		an[3]--;
		ans-=a[deep].e3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		
		memset(an,0,sizeof an);
		ans=0,maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].e1,&a[i].e2,&a[i].e3);
			int t=a[i].e1,b=a[i].e2,c=a[i].e3;
			if(t>=b&&t>=c){
				if(b>=c){
					a[i].d1=t;
					a[i].d2=b;
					a[i].d3=c;
					a[i].bi=1;
					a[i].md=2;
					a[i].mi=3;
				}
				else{
					a[i].d1=t;
					a[i].d2=c;
					a[i].d3=b;
					a[i].bi=1;
					a[i].md=3;
					a[i].mi=2;
				}
			}
			else if(c>=b&&c>t){
				if(b>=t){
					a[i].d1=c;
					a[i].d2=b;
					a[i].d3=t;
					a[i].bi=3;
					a[i].md=2;
					a[i].mi=1;
				}
				else{
					
					a[i].d1=c;
					a[i].d2=t;
					a[i].d3=b;
					a[i].bi=3;
					a[i].md=1;
					a[i].mi=2;
				}
			}
			else{
				if(t>=c){
					a[i].d1=b;
					a[i].d2=t;
					a[i].d3=c;
					a[i].bi=2;
					a[i].md=1;
					a[i].mi=3;
				}
				else{
					a[i].d1=b;
					a[i].d2=c;
					a[i].d3=t;
					a[i].bi=2;
					a[i].md=3;
					a[i].mi=1;
				}
			}
		}
		if(n<=15){
			dfs(1);
			printf("%d\n",maxx);
			continue;
		}
		sort(a+1,a+1+n,cmp);
		int an[9]={0,0,0,0,0,0};
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(an[a[i].bi]+1<=n/2){
				an[a[i].bi]++;
				sum+=a[i].d1;
			}
			else if(an[a[i].md]+1<=n/2){
				an[a[i].md]++;
				sum+=a[i].d2;
			}
			else{
				an[a[i].mi]++;
				sum+=a[i].d3;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
} 
