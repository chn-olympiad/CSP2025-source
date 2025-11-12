#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		int maxl=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++){
		 if(a[i]==a[j]){
				if(b[i]==b[j]){
					if(c[i]<c[j]){
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						swap(c[i],c[j]);
					}
				}
				}else if(a[i]==a[j]){
					if(c[i]==c[j]){
						if(b[i]<b[j]){
							swap(a[i],a[j]);
						    swap(b[i],b[j]);
						    swap(c[i],c[j]);
						}
					}
				}else if(b[i]==b[j]){
					if(c[i]==c[j]){
						if(b[i]<b[j]){
							swap(a[i],a[j]);
						    swap(b[i],b[j]);
						    swap(c[i],c[j]);
						}
					}
				}else if(a[i]==a[j]){
					if(b[i]<b[j]&&c[i]<c[j]){
						    swap(a[i],a[j]);
						    swap(b[i],b[j]);
						    swap(c[i],c[j]);
					}else if(b[i]<b[j]&&c[i]>c[j]){
						if(b[j]-b[i]>c[i]-c[j]){
							swap(a[i],a[j]);
						    swap(b[i],b[j]);
						    swap(c[i],c[j]);
					}
				}
			}
		}
		}
		int j=1;
		for(int i=1;i<=maxl;i++){
			ans+=a[j];
			j++;
		}
		for(int i=1;i<=maxl;i++){
			ans+=b[j];
			j++;
		}
		for(int i=1;i<=maxl;i++){
			ans+=c[j];
			j++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
