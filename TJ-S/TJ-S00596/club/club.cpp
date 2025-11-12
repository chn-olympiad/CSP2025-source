#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100005],b[100005],c[100005],d=0,e=0,f=0,ans1=114514;
	bool p[100005],q[100005],r[100005];
	unsigned long long int ans=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		d=0;
		e=0;
		f=0;
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		memset(r,0,sizeof(r));
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j]){
				if(b[j]>c[j]){
					c[j]=a[j]-b[j];
					d++;
					p[j]=1;
					ans+=a[j];
				}else if(a[j]>c[j]){
					b[j]=c[j];
					c[j]=a[j]-b[j];
					d++;
					p[j]=1;
					ans+=a[j];
				}else{
					b[j]=a[j];
					a[j]=c[j];
					c[j]=a[j]-b[j];
					f++;
					r[j]=1;
					ans+=a[j];
				}
			}else if(b[j]>a[j]){
				if(a[j]>c[j]){
					int temp=a[j];
					a[j]=b[j];
					b[j]=temp;
					c[j]=a[j]-b[j];
					e++;
					q[j]=1;
					ans+=a[j];
				}else if(b[j]>c[j]){
					a[j]=b[j];
					b[j]=c[j];
					c[j]=a[j]-b[j];
					e++;
					q[j]=1;
					ans+=a[j];
				}else{
					a[j]=c[j];
					c[j]=a[j]-b[j];
					f++;
					r[j]=1;
					ans+=a[j];
				}
			}else if(a[j]==b[j]){
				if(c[j]>a[j]){
					a[j]=c[j];
					c[j]=a[j]-b[j];
					f++;
					r[j]=1;
					ans+=a[j];
				}else if(c[j]<a[j]){
					c[j]=0;
					e++;
					q[j]=1;
					ans+=a[j];
				}
			}else if(a[j]==c[j]){
				if(b[j]>a[j]){
					a[j]=b[j];
					b[j]=c[j];
					c[j]=a[j]-b[j];
					e++;
					q[j]=1;
					ans+=a[j];
				}else if(b[j]<a[j]){
					b[j]=c[j];
					c[j]=a[j]-b[j];
					d++;
					p[j]=1;
					ans+=a[j];
				}
			}else if(c[j]==b[j]){
				if(a[j]>c[j]){
					c[j]=a[j]-b[j];
					d++;
					p[j]=1;
					ans+=a[j];
				}else if(c[j]>a[j]){
					a[j]=b[j];
					c[j]=a[j]-b[j];
					e++;
					q[j]=1;
					ans+=a[j];
				}
			}
		}
		if(d<=n/2&&e<=n/2&&f<=n/2){
			cout<<ans<<endl;
		}else if(d>n/2){
			ans1=0;
			int tempp=0;
			int temp=d-n/2;
			for(int j=1;j<=temp;j++){
				ans1=114514;
				int tempp=0;
				for(int i=1;i<=n;i++){
					if(p[i]&&c[i]<ans1){
						tempp=i;
						ans1=c[i];
					}
				}
				p[tempp]=0; 
				ans-=ans1;
			}
			cout<<ans<<endl;
			continue;
		}else if(e>n/2){
			ans1=0;
			int temp=e-n/2;
			int tempp=0;
			for(int j=1;j<=temp;j++){
				ans1=114514;
				int tempp=0;
				for(int i=1;i<=n;i++){
					if(q[i]&&c[i]<=ans1){
						tempp=i;
						ans1=c[i];
					}
				}
				q[tempp]=0; 
				ans-=ans1;
			}
			cout<<ans<<endl;
			continue;
		}else if(f>n/2){
			ans1=0;
			int temp=f-n/2;
			int tempp=0;
			for(int j=1;j<=temp;j++){
				ans1=114514;
				int tempp=0;
				for(int i=1;i<=n;i++){
					if(r[i]&&c[i]<=ans1){
						tempp=i;
						ans1=c[i];
					}
				}
				r[tempp]=0; 
				ans-=ans1;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}                                                                                    
