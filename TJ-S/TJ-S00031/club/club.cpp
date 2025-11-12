#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],d[100005],e[100005],f[100005],a1[100005],b1[100005],c1[100005],ans,cbs,x,w,cba; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int v=1;v<=t;v++){
		cin>>n;
		ans=0;
		x=0;
		w=0;
		cbs=0;
		cba=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];	
			a1[i]=a[i];
			b1[i]=b[i];
			c1[i]=c[i];
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				w=1;
				sort(a,a+n,greater<int>());
		        sort(b,b+n,greater<int>());
				for(int j=1;j<=n/2;j++){
					if(a[j]!=b[j]){
						cba=cba+a[j]+b[j];
					}
					else if(a[j]>b[j]){
						cba+=a[j];
						cba+=b[j+1];
					}
					else{
						cba+=b[j];
						cba+=a[j+1];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]==0&&c[i]==0){
				x=1;
				cba+=a[i];
			}
		}
		sort(a,a+n,greater<int>());
		sort(b,b+n,greater<int>());
		sort(c,c+n,greater<int>());
		for(int i=1;i<=n;i++){
			d[i]=a[i];
			e[i]=b[i];
			f[i]=c[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n/2;j++){
				if(a1[i]==d[j]&&b1[i]==e[j]&&c1[i]!=f[j]){
					if(d[j]>=e[j]){
						ans+=d[j];
						ans+=e[j+1];
					}
					else{
						ans+=e[j];
						ans+=d[j+1];
					}
				}
				if(b1[i]==e[j]&&c1[i]==f[j]&&a1[i]!=d[j]){
					if(e[j]>=f[j]){
						ans+=e[j];
						ans+=f[j+1];
					}
					else{
						ans+=f[j];
						ans+=e[j+1];
					}
				}
				if(c1[i]==f[j]&&a1[i]==d[j]&&b1[i]!=e[j]){
					if(f[j]>=d[j]){
						ans+=f[j];
						ans+=d[j+1];
					}
					else{
						ans+=d[j];
						ans+=f[j+1];
					}
				}
				if(a1[i]==d[j]&&b1[i]==e[j]&&c1[i]==f[i]){
					if(d[j]>e[j]&&d[j]>f[j]){
						ans+=d[j];
						if(e[j+1]>f[j+1]){
							ans+=e[j+1];
						}
						else{
							ans+=f[j+1];
						}
					if(e[j]>f[j]&&e[j]>d[j]){
							ans+=e[j];
							if(d[j+1]>f[j+1]){
							ans+=d[j+1];
						}
						else{
							ans+=f[j+1];
						}
						}
					else{
						ans+=f[j];
						if(e[j+1]>d[j+1]){
							ans+=e[j+1];
						}
						else{
							ans+=d[j+1];
						}
					}
					} 
				}
			}
		}
		if(x==1){
			cout<<cbs<<endl;
		}
		else if(w==1){
			cout<<cba<<endl;
		}
		else{
		    cout<<ans<<endl;
		}
	
	}
	return 0;
}

