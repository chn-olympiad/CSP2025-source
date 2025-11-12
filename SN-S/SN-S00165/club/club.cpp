//安奭颉 SN-S00165 西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001],c[100001],d[100001],sum,num,cum,ans;
bool cmp(int w,int r){
	return w>r;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		sum=0;
		num=0;
		cum=0;
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=100001;i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				ans+=x;	
				if(y>=z){
					a[++sum]=y-x;
				}
				else a[++sum]=z-x;
			}
			else if(y>=x&&y>=z){
				ans+=y;
				if(x>=z){
					b[++num]=x-y;
				}
				else b[++num]=z-y;
			}
			else{
				ans+=z;
				if(x>=y){
					c[++cum]=x-z;
				}
				else c[++cum]=y-z;
			}
		}
		if(sum>n/2){
			sort(a+1,a+sum+1,cmp);
			for(int i=1;i<=sum-n/2;i++){
				ans+=a[i];
			}
		}
		if(num>n/2){
			sort(b+1,b+num+1,cmp);
			for(int i=1;i<=num-n/2;i++){
				ans+=b[i];
			}
		}
		if(cum>n/2){
			sort(c+1,c+cum+1,cmp);
			for(int i=1;i<=cum-n/2;i++){
				ans+=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

