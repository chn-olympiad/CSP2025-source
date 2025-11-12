#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t;
int n;
int a[N][4];
int f[N];
int cnt[4];
int sum;
int q[N];
int num;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		num=0;
		sum=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int x=a[i][1],y=a[i][2],z=a[i][3];
			int mx=max(x,max(y,z));
			sum+=mx;
			if(mx==x){
				f[i]=1;
				cnt[1]++;
			}else if(mx==y){
				f[i]=2;
				cnt[2]++;
			}else{
				f[i]=3;
				cnt[3]++;
			}
		}
		int h=n/2;
		if(cnt[1]<=h&&cnt[2]<=h&&cnt[3]<=h){
			cout<<sum<<endl;
			continue;
		}
		int flag=0;
		for(int i=1;i<=3;i++) if(cnt[i]>h) flag=i;
		for(int i=1;i<=n;i++){
			if(f[i]==flag){
				int x=a[i][1],y=a[i][2],z=a[i][3];
				int c1,c2;
				if(flag==1){
					c1=x-y;
					c2=x-z;
				}else if(flag==2){
					c1=y-x;
					c2=y-z;
				}else{
					c1=z-x;
					c2=z-y;
				}
				q[++num]=min(c1,c2);
			}
		}
		sort(q+1,q+1+num);
		for(int i=1;i<=cnt[flag]-h;i++){
			sum-=q[i];
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 
