#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[5][N],b[N],c[N],d[N],cntb,cntc,cntd;
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		cntb=cntc=cntd=1;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=3;i++){
				cin>>a[i][j];
			}
		}
		for(int j=1;j<=n;j++){
			int mx=max(max(a[1][j],a[2][j]),a[3][j]);
			sum+=mx;
			if(a[1][j]==mx){
				b[cntb++]=a[1][j]-max(a[2][j],a[3][j]);
			}
			else if(a[2][j]==mx){
				c[cntc++]=a[2][j]-max(a[1][j],a[3][j]);
			}
			else{
				d[cntd++]=a[3][j]-max(a[2][j],a[1][j]);
			}
			//cout<<sum;
		}
		if(cntb-1>n/2){
			sort(b+1,b+cntb);
			for(int i=1;i<=cntb-1-(n/2);i++){
				sum-=b[i];
			}
		}
		else if(cntc-1>n/2){
			sort(c+1,c+cntc);
			for(int i=1;i<=cntc-1-(n/2);i++){
				sum-=c[i];
			}
		}
		else if(cntd-1>n/2){
			sort(d+1,d+cntd);
			for(int i=1;i<=cntd-1-(n/2);i++){
				sum-=d[i];
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
} 
