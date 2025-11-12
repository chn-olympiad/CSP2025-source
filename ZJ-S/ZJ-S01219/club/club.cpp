#include<bits/stdc++.h>
using namespace std;
int t,n;
int vis[100005]={0},ans=0;
int a[100005],b[100005],c[100005];
struct aaa{
	int aa,ww,zz;
};
bool cmp(int x,int y){
	return x>y;
}
bool cmp1(aaa x,aaa y){
	return x.aa>y.aa;
}
void f(int a1,int b1,int c1,int d){
	if(d==n){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(vis[i]==1)cnt+=a[i];
			else if(vis[i]==2)cnt+=b[i];
			else cnt+=c[i];

			 
		}

		ans=max(ans,cnt);
	}
	if(vis[d]==0){
		if(a1>0){
			vis[d]=1;
			f(a1-1,b1,c1,d+1);
			vis[d]=0;
		}
		if(b1>0){
			vis[d]=2;
			f(a1,b1-1,c1,d+1);
			vis[d]=0;
		}
		if(c1>0){
			vis[d]=3;
			f(a1,b1,c1-1,d+1);
			vis[d]=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
        
	    int a1[100005];
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];
		int mx1=-1,mx2=-1;
		for(int i=0;i<n;i++)mx1=max(mx1,b[i]);
		for(int j=0;j<n;j++)mx2=max(mx2,c[j]);
		if(mx1==0&&mx2==0){
			sort(a,a+n,cmp);
			for(int i=0;i<n/2;i++)ans+=a[i];
			cout<<ans<<endl;

		}else if(mx2==0){
			int sum=0;
			aaa g[100005]={0};
			int dd=0;
			for(int i=0;i<n;i++){
				if(a[i]>b[i]){
					g[dd].aa=a[i]-b[i];
					g[dd].ww=i;
					g[dd].zz=1;
					dd++;
				}else{
		        	g[dd].aa=b[i]-a[i];
					g[dd].ww=i;
					g[dd].zz=2;
					dd++;    
				}
				
			}
			sort(g,g+dd,cmp1);
			int hh=0,yy=0;
			for(int i=0;i<dd;i++){
				if(g[i].zz==1){
					if(hh<n/2){
					
					sum+=a[g[i].ww];
					hh++;
				}else sum+=b[g[i].ww];
				}
				if(g[i].zz==2){
					if(yy<n/2){
					
					sum+=b[g[i].ww];
					yy++;
				}else sum+=a[g[i].ww];
				}
			}
			cout<<sum<<endl;
			
		}else{
		
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				int k=n-i-j;
				if(k>n/2)continue;
				f(i,j,k,0);
				for(int i=0;i<1000;i++)vis[i]=0;

			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	}

	return 0;
}
