#include <bits/stdc++.h>

using namespace std;
int t,n,a[100005],b[100005],c[100005],e[100005],d[100005],maxx1 = 0,maxx2 = 0,f[5];
int xjb(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	f[1] = 0;
	f[2] = 0;
	f[3] = 0;
	for(int i = 1;i<=t;i++){
		int ww = 0,qq = 0,pp = 0,ans = 0,sum = 0,cnt = 0,minn = 999999,minn2 = 999999,minn3 = 999999,r = 0;
		cin>>n;
		for(int j = 1;j<=n;j++){
			cin>>a[j];
			cin>>b[j];
			cin>>c[j];
			maxx1 = max(a[j],b[j]);
			maxx2 = max(maxx1,c[j]);
			cnt += maxx2;
			if(maxx2 == a[j]){
				f[1]++;
			}
			else if(maxx2 == b[j]){
				f[2]++;
			}
			else{
				f[3]++;
			}
			ww+=a[j];
			qq+=b[j];
			pp+=c[j];
		}
		if(pp == 0){
			if(qq == 0){
				sort(a+1,a+1+n,xjb);
				for(int j = 1;j<=n/2;j++){
					ans += a[j];
				}
				cout<<ans<<endl;
			}
			else if(ww == 0){
				sort(b+1,b+1+n,xjb);
				for(int j = 1;j<=n/2;j++){
					sum += b[j];
				}
				cout<<sum<<endl;
			}
			else{
				sort(a+1,a+1+n,xjb);
				sort(b+1,b+1+n,xjb);
				for(int j = 1;j<=n/2;j++){
					ans+=a[j];
					sum+=b[j];
				}
				cout<<ans+sum<<endl;
			}
		}
		else{
			if(f[1] <= n/2 && f[2] <= n/2 && f[3] <= n/2){
				cout<<cnt<<endl;
			}
			else if(f[1] > n/2 && f[2] + 1 <= n/2 ||f[1] > n/2 && f[3]+1 <= n/2){
				for(int j = 1;j<=n;j++){
					if(a[j] > b[j]){
						d[j] = a[j] - b[j];
						minn = min(minn,d[j]);
					}
					if(a[j]>c[j]){
						e[j] = a[j] - c[j];
						minn2 = min(minn2,e[j]);
					}
				}
				minn3 = min(minn,minn2);
				r = cnt-minn3;
				cout<<r<<endl;
			}
			else if(f[2] > n/2 && f[1] + 1 <= n/2 ||f[2] > n/2 && f[3]+1 <= n/2){
				for(int j = 1;j<=n;j++){
					if(b[j] > a[j]){
						d[j] = b[j] - a[j];
						minn = min(minn,d[j]);
					}
					if(b[j]>c[j]){
						e[j] = b[j] - c[j];
						minn2 = min(minn2,e[j]);
					}
				}
				minn3 = min(minn,minn2);
				r = cnt-minn3;
				cout<<r<<endl;
			}
			else{
				for(int j = 1;j<=n;j++){
					if(c[j] > a[j]){
						d[j] = c[j] - a[j];
						minn = min(minn,d[j]);
					}
					if(c[j]>b[j]){
						e[j] = c[j] - b[j];
						minn2 = min(minn2,e[j]);
					}
				}
				minn3 = min(minn,minn2);
				r = cnt-minn3;
				cout<<r<<endl;
			}
		}
	}
	
	return 0;
} 
