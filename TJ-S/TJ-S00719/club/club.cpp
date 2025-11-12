#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[100010],b[100010],c[100010],q[50005],r[50005],t[50005],a1=1,b1=1,c1=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(max(max(a[i],b[i]),c[i])==a[i]){
				if(a1<=n/2){
					q[a1]=a[i];
					a1++;
				}
				else{
					int minn=a[i],mini=i;
					for(int j=1;j<=a1;j++){
						if(minn>=q[j]){
							minn=q[j];
							mini=j;
						}
					}
					if(mini!=i)
					q[mini]=a[i];
					if(b[mini]>c[mini]){
						r[mini]=minn;
						b1++;
					}
					else{
						t[mini]=minn;
						c1++;
					}
				}
			}
			else if(max(max(a[i],b[i]),c[i])==b[i]){
				if(b1<=n/2){
					r[b1]=b[i];
					b1++;
				}
				else{
					int minn=b[i],mini=i;
					for(int j=1;j<=b1;j++){
						if(minn>=r[j]){
							minn=r[j];
							mini=j;
						}
					}
					if(mini!=i)
					r[mini]=b[i];
					if(a[mini]>c[mini]){
						q[mini]=minn;
						a1++;
					}
					else{
						t[mini]=minn;
						c1++;
					}
				}
			}
			else{
				if(c1<=n/2){
					t[c1]=c[i];
					c1++;
				}
				else{
					int minn=c[i],mini=i;
					for(int j=1;j<=c1;j++){
						if(minn>=t[j]){
							minn=t[j];
							mini=j;
						}
					}
					if(mini!=1)
					t[mini]=c[i];
					if(a[mini]>b[mini]){
						q[mini]=minn;
						a1++;
					}
					else{
						r[mini]=minn;
						b1++;
					}
				}
			}
		}
		int ans=0;
		for(int j=1;j<=a1;j++){
			ans+=q[j];
			q[j]=0;
		}
		for(int j=1;j<=b1;j++){
			ans+=r[j];
			r[j]=0;
		}
		for(int j=1;j<=c1;j++){
			ans+=t[j];
			t[j]=0;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

