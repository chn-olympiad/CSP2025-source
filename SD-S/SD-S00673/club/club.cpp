#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T;
int n;
int ans=0;
int a[MAXN],b[MAXN],c[MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		
		for(int i=1;i<=n;i++){
				if(b[i]==0&&c[i]==0){
				sort(a,a+n+1);
					if(i>m){
						ans+=a[i];
					}
				}
				else if(c[i]==0){
					int y[MAXN];
					y[i]=max(a[i],b[i]);
					sort(y,y+n+1);
					if(i>m){
						ans+=y[i];
					}
				}
				else{
					int x[MAXN];
					x[i]=max(a[i],max(b[i],c[i]));
					ans+=x[i];
				}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
