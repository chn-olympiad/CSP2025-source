#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,c[5],sum;
struct node{
	int mx,m,mx2,m2,mm;
};
node a[100005];
bool f(node a,node b){
	return a.mm>b.mm;	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>T;
	while (T--){
		sum=0;
		memset(c,0,sizeof(c));
		cin>>n;
		for (int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i].mx=max(x,max(y,z));
			if (x==a[i].mx){
				a[i].m=1;
				a[i].mx2=max(y,z);
				if (y>=z){
					a[i].m2=y;
				}
				else{
					a[i].m2=z;
				}
			}
			else if (y==a[i].mx){
				a[i].m=2;
				a[i].mx2=max(x,z);
				if (x>=z){
					a[i].m2=x;
				}
				else{
					a[i].m2=z;
				}
			}
			else{
				a[i].m=3;
				a[i].mx2=max(y,x);
				if (y>=x){
					a[i].m2=y;
				}
				else{
					a[i].m2=x;
				}
			}
			a[i].mm=a[i].mx-a[i].mx2;			
		}
		sort(a+1,a+n+1,f); 
		for (int i=1;i<=n;i++){
			if (c[a[i].m]==n/2){
				c[a[i].m2]++;
				sum+=a[i].mx2;
			}
			else{
				c[a[i].m]++;
				sum+=a[i].mx;				
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
} 