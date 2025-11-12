#include<bits/stdc++.h>
using namespace std;
int g[5009],f[5009],w[5009],n,t,mx=INT_MIN,xz;
bool cmp(int x,int y){
	return x>y;
}
int zd(int x,int y){
	int ans=1;
	for(int i=x;i>=x-y+1;i--){
		ans*=i;
		ans%=998244353;
		//cout<<i;
	}
	for(int i=1;i<=y;i++)ans/=i;
	return ans;
}
int qp(int x,int y,int ans){
	if(x==n+1){
		if(ans<=xz)return 0;
		if(y<3)return 0;
		return 1;
	}
	return (qp(x+1,y+1,ans+w[x])+qp(x+1,y,ans))%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		mx=max(mx,w[i]);
	}
	if(n==3){
		if((w[1]+w[2]>w[3])&&(w[1]+w[3]>w[2])&&(w[2]+w[3]>w[1]))cout<<1;
		else cout<<0;
		return 0;
	}
	if(mx==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=zd(n,i);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(w+1,w+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		xz=w[i];
		ans+=qp(i+1,1,0);
		ans%=998244353;
	}
	cout<<ans;
	/*for(int I=1;I<=n;I++){
		memset(f,0,sizeof(f));
		int W=w[I];//别忘了初始化
		for(int i=I+1;i<=n;i++){
			for(int j=W;j>=w[i];j--){
				//if(f[j-w[i]]+1>f[j]){
					//cout<<i<<"\n";
					//f[j]=f[j-w[i]]+1;
						f[j]++;
						f[j]+=f[j-1];
					g[j]=g[j-w[i]]+1;
				//}
				//f[j]=max(f[j],f[j-w[i]]+1);
				if(g[j]<2)f[j]=0;
				//cout<<g[j]<<" "<<f[j]<<" "<<j<<"\n";
			}
		}
		t+=f[W];
		t%=998244353;
	}
	cout<<t;//别忘了取模 
*/
}//998244353
