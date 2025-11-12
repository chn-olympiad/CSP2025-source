#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],x[100010],y[100010],z[100010],sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i] >> b[i] >> c[i];
			x[i]=a[i],y[i]=b[i],z[i]=c[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		for(int i=n-1;i>=n/2;i--){
			if(a[i]>=b[i]&&a[i]>=c[i]&&a[i]!=-1){
				sum+=a[i];
				for(int j=0;j<n;j++){
					if(x[j]==a[i]){
						a[i]=-1;
						b[i]=-1;
						c[i]=-1;
					}
				}
			}else{
				continue;
			}
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		for(int i=n-1;i>=n/2;i--){
			if(b[i]>=a[i]&&b[i]>=c[i]&&b[i]!=-1){
				sum+=b[i];
				for(int j=0;j<n;j++){
					if(y[j]==b[i]){
						a[i]=-1;
						b[i]=-1;
						c[i]=-1;
					}
				}
			}else{
				continue;
			}
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		for(int i=n-1;i>=n/2;i--){
			if(c[i]>=a[i]&&c[i]>=b[i]&&c[i]!=-1){
				sum+=c[i];
				for(int j=0;j<n;j++){
					if(z[j]==c[i]){
						a[i]=-1;
						b[i]=-1;
						c[i]=-1;
					}
				}
			}else{
				continue;
			}
		}
		cout << sum;
		sum=0;
	}
	return 0;
}
