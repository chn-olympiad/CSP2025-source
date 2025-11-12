#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int N=1e5+10;
long long t,n,a[N],b[N],c[N],d[N],e[N],f[N],g[N],h[N],l[N],x[N],y[N],z[N],man=0,ans=0,aaa=0,sum=0,cnt=0,res=0,kkk=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			d[i]=a[i]-b[i];
			e[i]=b[i]-c[i];
			f[i]=a[i]-c[i];
			x[i]=a[i];
			y[i]=b[i];
			z[i]=c[i];
			g[i]=d[i];
			h[i]=e[i];
			l[i]=f[i];
			if(d[i]<0)d[i]=-d[i];
			if(e[i]<0)e[i]=-e[i];
			if(f[i]<0)f[i]=-f[i];
		}
		sort(x+1,x=n+1);
		sort(y+1.y+n+1);
		sort(z+1,z+n+1);
		for(int i=1;i<=n;i++){
			if(y[i]!=0){
				man=1;
				if(z[i]!=0){
					man=2;
					break;
				}
			}
		}
		for(int i=n;i>=1;i--){
			if(n==2){
				if(x[i]>y[i]&&x[i]>z[i]){
					if(y[i]>z[i]){
						cout<<x[i]+y[i];
						return 0;
					}
					if(y[i]<z[i]){
						cout<<x[i]+z[i];
						return 0;
					}
				}
				if(x[i]<y[i]&&y[i]>z[i]){
					if(x[i]>z[i]){
						cout<<x[i]+y[i];
						return 0;
					}
					if(x[i]<z[i]){
						cout<<y[i]+z[i];
						return 0;
					}
				}
				if(x[i]<y[i]&&z[i]>y[i]){
					if(x[i]>y[i]){
						cout<<x[i]+z[i];
						return 0;
					}
					if(x[i]<y[i]){
						cout<<y[i]+z[i];
						return 0;
					}
				}
			}
			if(man==1){
				aaa+=y[i];
				aaa+=x[i];
				if(i==(n/2+1)){
					cout<<aaa;
					return 0;
				}
			}
			if(man==0){
				for(int i=n;i>n/2;i--)aaa+=x[i];
				cout<<aaa;
				return 0;
			}
		}
		
		for(int i=n;i>=1;i--){
			if(d[i]>e[i]&&d[i]>f[i]){
				for(int j=1;j<=n;j++){
					if(g[j]==d[i]){
						kkk=1;
						cnt++;
						sum+=a[i];
					}
				}
				if(kkk==0){
					for(int j=1;j<=n;j++){
						if(-g[j]==d[i]){
							ans++;
							sum+=b[j];
							break;
						}
					}
				}
				kkk=0;
			}
			if(e[i]>d[i]&&e[i]>f[i]){
				for(int j=1;j<=n;j++){
					if(h[j]==e[i]){
						kkk=1;
						ans++;
						sum+=b[i];
						break;
					}
				}
				if(kkk==0){
					for(int j=1;j<=n;j++){
						if(-h[j]==e[i]){
							res++;
							sum+=c[i];
							break;
						}
					}
				}
				kkk=0;
			}
			if(f[i]>d[i]&&f[i]>e[i]){
				for(int j=1;j<=n;j++){
					if(l[j]==f[i]){
						kkk=1;
						res++;
						sum+=c[i];
						break;
					}
				}
			}
			if(kkk==0){
				for(int j=1;j<=n;j++){
					if(-l[j]==f[i]){
						cnt++;
						sum+=a[i];
						break;
					}
				}
			}
			kkk=0;
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
1
4
2 4 0
4 7 0
9 4 0
3 6 0
*/
