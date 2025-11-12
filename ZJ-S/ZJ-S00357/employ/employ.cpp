#include<bits/stdc++.h>
#define int long long
#define N 1010
using namespace std;
int n,m,i,ans,c[N],b[N],a[N],f[N];char s[N];
const int mod=998244353;
void sc(int t,int sa,int as){
	if(as==m){
		ans+=a[n+1-t];
		ans%=mod;return;
	}
	if(t==n+1){
		return;
	}
	int i;
	for(i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;b[t]=i;
			if(s[t]=='1'&&c[i]>sa)sc(t+1,sa,as+1);
			else sc(t+1,sa+1,as);
			f[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>s[i];
	for(i=1;i<=n;i++)cin>>c[i];
	a[0]=1;
	for(i=1;i<=n;i++)a[i]=(i*a[i-1])%mod;
	sc(1,0,0);
	cout<<ans%mod;
	return 0;
}
/*
		for(i=1;i<=k;i++){
			f[x[i]][y[i]]=0;xd2=rand()%4;
			xc=x[i],yc=y[i];
			if(xd2==0)xc++;if(xd2==1)xc--;
			if(xd2==2)yc++;if(xd2==3)yc--;
			while(xc<0||xc>n||yc<0||yc>m){
				xd2=rand()%4;
				if(xd2==0)xc=x[i]+1;if(xd2==1)xc=x[i]-1;
				if(xd2==2)yc=y[i]+1;if(xd2==3)yc=y[i]-1;
			}
			x[i]=xc,y[i]=yc;
			f[x[i]][y[i]]=11;
			if(x[i]==xa&&y[i]==ya){
				system("cls");
				cout<<"Game Over!\n";Sleep(1000);
				cout<<"You are die!";return 0;
			}
		}
		if(xd=='o'&&lt>0){
			for(i=1;i<=k;i++){
				if(x[i]>=(xa-n)&&x[i]<=(xa+n)&&
				y[i]>=(ya-m)&&y[i]<=(ya+m)){
					f[x[i]][y[i]]=0;
					for(j=i;j<k;j++)x[j]=x[j+1],y[j]=y[j+1];
					i--;k--;lt--;
				}
			}
		}
*/