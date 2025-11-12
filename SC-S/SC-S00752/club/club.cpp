#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,n,a[N][10],b[N],c[N],d[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
			c[i]=a[i][2];
			d[i]=a[i][3];
		}
		if(n==2){
			for(int i=1;i<=3;i++)
				for(int j=1;j<=3;j++)
					if(i!=j) ans=max(ans,a[1][i]+a[2][j]);
			cout<<ans<<endl;
			continue;
		}
		if(n==4){
			long long cnta=0,cntb=0,cntc=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int x=1;x<=3;x++){
							cnta=0;
							cntb=0;
							cntc=0;
							if(i==1) cnta++;
							else if(i==2) cntb++;
							else cntc++;
							if(j==1) cnta++;
							else if(j==2) cntb++;
							else cntc++;
							if(k==1) cnta++;
							else if(k==2) cntb++;
							else cntc++;
							if(x==1) cnta++;
							else if(x==2) cntb++;
							else cntc++;
							if(cnta<=2&&cntb<=2&&cntc<=2){
								ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][x]);
							}
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;			
		}
		sort(b+1,b+1+n,cmp);
		long long m=n;
		for(int i=1;i<=m/2;i++){
			ans+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 