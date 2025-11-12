#include<bits/stdc++.h>
using namespace std;
int f(int n){
	int a[n],b[n],c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int ans=0,x=0,y=0,z=0,q=n/2;
	for(int i=0;i<n;i++){
		if(a[i]>b[i]){
			if(a[i]>c[i]){
				if(x<q){
					x++;
					ans+=a[i];
					continue;
				}else{
					if(b[i]>c[i]){
						if(y<q){
							y++;
							ans+=b[i];
							continue;
						}else{
							z++;
							ans+=c[i];
							continue;
						}
					}else{
						if(z<q){
							z++;
							ans+=c[i];
							continue;
						}else{
							y++;
							ans+=b[i];
							continue;
						}
					}
				}
			}else{
				if(z<q){
					z++;
					ans+=c[i];
					continue;
				}else{
					if(x<q){
						x++;
						ans+=a[i];
						continue;
					}else{
						y++;
						ans+=b[i];
						continue;
					}
				}
			}
		}else{
			if(b[i]>c[i]){
				if(y<q){
					y++;
					ans+=b[i];
					continue;
				}else{
					if(a[i]>c[i]){
						if(x<q){
							x++;
							ans+=a[i];
							continue;
						}else{
							z++;
							ans+=c[i];
							continue;
						}
					}else{
						if(z<q){
							z++;
							ans+=c[i];
							continue;
						}else{
							x++;
							ans+=a[i];
							continue;
						}
					}
				}
			}else{
				if(z<q){
					z++;
					ans+=c[i];
					continue;
				}else{
					if(y<q){
						y++;
						ans+=b[i];
						continue;
					}else{
						x++;
						ans+=a[i];
						continue;
					}
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,a[t];
	int n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		a[i]=f(n);
	}
	for(int i=1;i<=t;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
