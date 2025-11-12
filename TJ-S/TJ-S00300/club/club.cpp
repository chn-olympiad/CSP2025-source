#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int x[50009],y[50009],z[50009];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int f=1,ans=0;
		if(n==2){
			int h[4],l[4];
			cin>>h[1]>>h[2]>>h[3];
			cin>>l[1]>>l[2]>>l[3];
			ans=max(l[1]+h[2],l[2]+h[1]);
			ans=max(ans,l[3]+h[1]);
			ans=max(ans,l[1]+h[3]);
			ans=max(ans,l[2]+h[3]);
			ans=max(ans,l[3]+h[2]);
			cout<<ans;
			continue;
		}
		for(int j=1;j<=n*3;j++){
			cin>>a[j];
			if(j%3==0){
				if(a[j]!=0||a[j-1]!=0){
					f=0;
				}
			}
		}
		if(f==1){
			int tt[n+5],r=1;
			for(int j=1;j<=n*3;j+=3){
				tt[r]=a[j];
				r++;
			}
			sort(tt+1,tt+r-1);
			for(int j=r-1;j>n/2;j--){
				ans+=tt[j];
			}
			cout<<ans<<endl;
			continue;
		}
		int u=0,v=0,w=0;
		for(int j=1;j<=n*3;j+=3){
			b[j]=abs(a[j]-a[j+1]);
			b[j+1]=abs(a[j+1]-a[j+2]);
			b[j+2]=abs(a[j]-a[j+2]);
			if(a[j]>a[j+1]){
				if(a[j]>a[j+2]){
					u++;
					x[u]=j;
				}else{
					w++;
					z[w]=j+2;
				}
			}else{
				if(a[j+1]>a[j+2]){
					v++;
					y[v]=j+1;
				}else{
					w++;
					z[w]=j+2;
				}
			}
		}
		for(int j=1;j<=u;j++){
			ans+=a[x[j]];
		}
		for(int j=1;j<=v;j++){
			ans+=a[y[j]];
		}
		for(int j=1;j<=w;j++){
			ans+=a[z[j]];
		}
		if(u>n/2){
			int c[u+5];
			for(int j=1;j<=u;j++){
				if(b[x[j]]>b[x[j]+2]){
					c[j]=b[x[j]+2];
					w++;
					z[w]=x[j]+2;
				}else {
					c[j]=b[x[j]];
					v++;
					y[v]=x[j]+1;
				}
			}
			sort(c,c+u+1);
			for(int j=1;j<=u-(n/2);j++){
				ans-=c[j];
			}
			if(v>(n/2)){
				int d[v+5];
				for(int j=1;j<=v;j++){
					d[j]=b[y[j]+1];
				}
				sort(d,d+v+1);
				for(int j=0;j<v-(n/2);j++){
					ans-=d[j];
				}
			}else if(w>(n/2)){
				int d[w+5];
				for(int j=1;j<=v;j++){
					d[j]=b[z[j]];
				}
				sort(d,d+w+1);
				for(int j=0;j<w-(n/2);j++){
					ans-=d[j];
				}
			}
		}else if(v>n/2){
			int c[v+5];
			for(int j=1;j<=v;j++){
				if(b[y[j]]<b[y[j]-1]){
					c[j]=b[y[j]+1];
					w++;
					z[w]=x[j]+1;
				}else {
					c[j]=b[y[j]];
					u++;
					x[u]=y[j]-1;
				}
			}
			sort(c,c+v+1);
			for(int j=0;j<v-(n/2);j++){
				ans-=c[j];
			}
			if(u>(n/2)){
				int d[u+5];
				for(int j=1;j<=u;j++){
					d[j]=b[x[j]+2];
				}
				sort(d,d+u+1);
				for(int j=0;j<u-(n/2);j++){
					ans-=d[j];
				}
			}else if(w>(n/2)){
				int d[w+5];
				for(int j=1;j<=w;j++){
					d[j]=b[z[j]];
				}
				sort(d,d+w+1);
				for(int j=0;j<w-(n/2);j++){
					ans-=d[j];
				}
			}
		}else if(w>n/2){
			int c[w+5];
			for(int j=1;j<=w;j++){
				if(b[z[j]]>b[z[j]-1]){
					c[j]=b[z[j]-1];
					v++;
					y[v]=z[j]-1;
				}else {
					c[j]=b[z[j]];
					u++;
					x[u]=z[j]-2;
				}
			}
			sort(c,c+u+1);
			for(int j=0;j<u-(n/2);j++){
				ans-=c[j];
			}
			if(v>(n/2)){
				int d[v+5];
				for(int j=1;j<=v;j++){
					d[j]=b[y[j]-1];
				}
				sort(d,d+v+1);
				for(int j=0;j<v-(n/2);j++){
					ans-=d[j];
				}
			}else if(u>(n/2)){
				int d[u+5];
				for(int j=1;j<=u;j++){
					d[j]=b[x[j]+1];
				}
				sort(d,d+u+1);
				for(int j=0;j<u-(n/2);j++){
					ans-=d[j];
				}
			}
		}
		cout<<ans<<endl;
		fill(x,x+n,0);
		fill(y,y+n,0);
		fill(z,z+n,0);
	}
	return 0;
}
