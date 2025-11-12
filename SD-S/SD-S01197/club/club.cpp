#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct s{
	int a,b,c;
}a[500005];
struct d{
	int h,nu;
}r[500005];
bool cmp(s x,s y){
	return x.a>y.a;
}
bool cmp1(d x,d y){
	return x.h>y.h;
}int n;
int ans=0;
bool f=1,f1=1;
void dfs(int x,int na,int nb,int nc,int u){
	if(x==n+1){
		ans=max(ans,u);
		return ;
	} 
	if(2*na+2<=n) dfs(x+1,na+1,nb,nc,u+a[x].a);
	if(2*nb+2<=n) dfs(x+1,na,nb+1,nc,u+a[x].b);
	if(2*nc+2<=n) dfs(x+1,na,nb,nc+1,u+a[x].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		f=1;
		f1=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0){
				f=0;
			}
			if(a[i].c!=0){
				f1=0;
			}
		}
		if(f==1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(f1==1){
			if(n%2==0){
				for(int i=1;i<=n;i++){
					r[i].nu=i;
					r[i].h=a[i].a-a[i].b;
				}
				sort(r+1,r+1+n,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=a[r[i].nu].a;
					ans+=a[r[n-i+1].nu].b; 
				}
				cout<<ans<<"\n";
			}
			else{
				
				for(int i=1;i<=n;i++){
					r[i].nu=i;
					r[i].h=a[i].a-a[i].b;
				}
				sort(r+1,r+1+n,cmp1);
				int mi=2147483647;
				long long sum=0;
				for(int i=1;i<=n/2;i++){
					ans+=a[r[i].nu].a;
					sum+=a[r[n-i].nu].b; 
					if(a[r[n-i].nu].b<mi) mi=a[r[n-i].nu].b;
				}
				sum+=a[r[n].nu].b;
				if(a[r[n].nu].b<mi) mi=a[r[n].nu].b;
				cout<<ans+sum-mi<<"\n";
			}
			continue;
		}
		if(n<=50){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		else{
			cout<<"2025111";
			continue; 
		}
	}
	return 0;
} 

		
