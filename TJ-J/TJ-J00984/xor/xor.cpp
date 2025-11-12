#include<bits/stdc++.h>
using namespace std;
int n,kk,a[500005],f[1005][1005],ans=0,g[1005][1005];
int yihuo(int x,int y){
	int p[25],q[25],pq[25],sum=0;
	int cnt1=0,cnt2=0;
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	memset(pq,0,sizeof(pq));
	while(x!=0){
		p[++cnt1]=x%2;
		x/=2;
	}
	while(y!=0){
		q[++cnt2]=y%2;
		y/=2;
	}
	for(int i=1;i<=max(cnt1,cnt2);i++){
		if(p[i]==q[i]){
			pq[i]=0;
		}else{
			pq[i]=1;
		}
		sum=sum+pq[i]*pow(2,i-1);
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>kk;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			f[i][i]=a[i];
			for(int j=i+1;j<=n;j++){
				f[i][j]=yihuo(f[i][j-1],a[j]);
//				if(i==2&&j==4){
//					cout<<f[i][j]<<endl;
//				}
				if(f[i][j]==kk){
					g[i][j]=1;
			//	cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
				}
			}
			if(f[i][i]==kk){
				g[i][i]=1;
			}
			//cout<<f[2][4]<<endl;
			
		}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(g[i][j]==1){
				ans++;
				i=j;
				//cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}
	//cout<<yihuo(1,0);
	cout<<ans;
	return 0;
}
