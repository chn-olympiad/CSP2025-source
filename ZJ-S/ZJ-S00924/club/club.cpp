#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],e,f[205][205][205],m=-1,ans=-1;
long long s;
int maxx(int a,int b){
	if(a>b)return a;
	else return b;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		
		cin>>n;
		if(n>200){
			s=0;
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				s+=a[i];
			}
			cout<<s<<endl;
		}else {
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
			}
			for(int i=1;i<=n;i++){
				for(int q=0;q<=i&&q<=n/2;q++){
					for(int w=0;w<=i&&w<=n/2;w++){
						e=i-q-w;
						if(e<0)break;
						if(e>n/2||q>n/2||w>n/2)continue;
						if(e!=0)f[q][w][e]=maxx(f[q][w][e-1]+c[i],f[q][w][e]);
						if(q!=0)f[q][w][e]=maxx(f[q-1][w][e]+a[i],f[q][w][e]);
						if(w!=0)f[q][w][e]=maxx(f[q][w-1][e]+b[i],f[q][w][e]);
					}
				}
			}
			ans=-1;
			for(int q=0;q<=n/2;q++){
				for(int w=0;w<=n/2;w++){
					e=n-q-w;
					if(e<0)break;
					ans=maxx(ans,f[q][w][e]);
				}
			}
		
		
			cout<<ans<<endl;
		}
	}
	return 0;
}
