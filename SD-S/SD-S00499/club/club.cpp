#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+10,N2=110;
ll f[2][N2][N2][N2],a[N][4],f2[N];
int n,t;

ll read(){
	char c=getchar();
	ll s=0,p=1;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f));
		if(n<=200){
			for(int i=1;i<=n;i++){
				a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(n>>1,i);j++){
					for(int k=max(i-min(n>>1,i)-j,0);k<=min(n>>1,i);k++){
						if((j+k)>i) break;
						int h=i-j-k,p=i%2;
						if(j) f[p][j][k][h]=max(f[p][j][k][h],f[!p][j-1][k][h]+a[i][1]);
						if(k) f[p][j][k][h]=max(f[p][j][k][h],f[!p][j][k-1][h]+a[i][2]);
						if(h) f[p][j][k][h]=max(f[p][j][k][h],f[!p][j][k][h-1]+a[i][3]);
	//					cout<<i<<" "<<j<<" "<<k<<" "<<h<<" "<<f[p][j][k][h]<<endl;
					}
				}
			}
			int p=n%2;
			ll ans=f[p][1][0][0];
			for(int j=0;j<=n>>1;j++){
				for(int k=0;k<=n>>1;k++){
					for(int h=0;h<=n>>1;h++){
						ans=max(ans,f[p][j][k][h]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else{
			int flag=1,maxa;
			ll ans3=0;
			for(int i=1;i<=n;i++){
				a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
				f2[i]=a[i][1];
				maxa=max(a[i][1],max(a[i][2],a[i][3]));
				if(a[i][3]) flag=3;
				else if(a[i][2]&&flag==1) flag=2;
				ans3+=maxa;
			}
			switch(flag){
				case 1:
					sort(f2+1,f2+1+n,cmp);
					ll ans1;
					for(int i=1;i<=(n>>1);i++){
						ans1+=f2[i];
					}
					cout<<ans1<<endl;
					break;
				case 2:
					sort(f2+1,f2+1+n,cmp);
					ll ans2;
					for(int i=1;i<=(n>>1);i++){
						ans2+=f2[i];
					}
					cout<<ans2<<endl;
					break;
				case 3:
					cout<<ans3<<endl;
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
