#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans;
int a[N][3],f[N];
struct Node{
	int cha;
	int id;
}s[N];
bool cmp(Node x,Node y){
	return x.cha<=y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n+1;i++) f[i]=0;
		long long ans=0;
		
		for(int m=1;m<=2;m++){
			for(int i=1;i<=n+1;i++) s[i].cha=s[i].id=0;
			int sum=0;
			for(int i=1;i<=n;i++){
				if(f[i]==1) continue;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				sum++,ans+=a[i][1];
				s[sum].cha=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				s[sum].id=i;
			}
			}
				int c=0;
				if(sum>n/2){
					sort(s+1,s+sum+1,cmp);
					while(sum-c>n/2){
						c++;
						ans=ans-a[s[c].id][1];
						a[s[c].id][1]=0;
				
					}
				}
				while(c<sum){
						c++;
						f[s[c].id]=1;
					}
		for(int i=1;i<=n+1;i++) s[i].cha=s[i].id=0;
		sum=0;
		for(int i=1;i<=n;i++){
				if(f[i]==1) continue;
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				sum++,ans+=a[i][2];
				s[sum].cha=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				s[sum].id=i;
			}
		}
				c=0;
				if(sum>n/2){
					sort(s+1,s+sum+1,cmp);
					while(sum-c>n/2){
						c++;
						ans=ans-a[s[c].id][2];
						a[s[c].id][2]=0;
					}
				}
				while(c<sum){
						c++;
						f[s[c].id]=1;
					}
for(int i=1;i<=n+1;i++) s[i].cha=s[i].id=0;
		sum=0;
		for(int i=1;i<=n;i++){
				if(f[i]==1) continue;
			if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				sum++,ans+=a[i][3];
				s[sum].cha=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
				s[sum].id=i;
			}
		}
				c=0;
				if(sum>n/2){
					sort(s+1,s+sum+1,cmp);
					while(sum-c>n/2){
						c++;
						ans=ans-a[s[c].id][3];
						a[s[c].id][3]=0;
					}
				}
				while(c<sum){
						c++;
					f[s[c].id]=1;
					}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
