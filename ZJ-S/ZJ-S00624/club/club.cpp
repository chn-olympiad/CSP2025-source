#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
#define ll long long
int a[N],b[N],c[N];
int aa[N],bb[N],cc[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ll sum=0;
		int n;
		cin>>n;
		int a1=1,b1=1,c1=1;
		int z[N],x[N],w[N];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				z[a1]=min(a[i]-b[i],a[i]-c[i]);
				sum+=a[i];
				a1++;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				x[b1]=min(b[i]-a[i],b[i]-c[i]);
				sum+=b[i];
				b1++;
			}else {
				w[c1]=min(c[i]-a[i],c[i]-b[i]);
				sum+=c[i];
				c1++;
			}
		}
		if(a1-1>n/2){
			int i=1;
			sort(z+1,z+a1);
			while(a1-1>n/2){
				sum-=z[i];
				i++;
				a1--;
			}
		}
		if(b1-1>n/2){
			int i=1;
			sort(x+1,x+b1);
			while(b1-1>n/2){
				sum-=x[i];i++;
				b1--;
			}
		}
		if(c1-1>n/2){
			int i=1;
			sort(w+1,w+c1);
			while(c1-1>n/2){
				sum-=w[i];i++;
				c1--;
			}
		}
		cout<<sum<<'\n';
	}
}
