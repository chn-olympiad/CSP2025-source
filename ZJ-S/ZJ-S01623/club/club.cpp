#include<bits/stdc++.h>
#define LL long long
using namespace std;

int a[111111][4];

int wh[111111][4];

int d[111111];

int p[4];

int dd[111111];

LL t,ans;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout.tie(0);
	
	int tt__t;
	
	cin >> tt__t;
	while(tt__t--){
		ans=0;
		t=0;
		memset(p,0,sizeof(p));
		memset(wh,0,sizeof(wh));
		memset(dd,0,sizeof(dd));
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		
		int n;
	
		cin >> n;
		
		for(int i=1;i<=n;i++){
			
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			
			int maxa=max(a[i][1],max(a[i][2],a[i][3]));
			
			for(int j=1;j<=3;j++){
				
				if(a[i][j]==maxa){
					
					p[j]++;
					
					wh[i][j]=1;
					
					d[i]=maxa-(a[i][1]+a[i][2]+a[i][3]-maxa-min(a[i][1],min(a[i][2],a[i][3])));
					
				}
				
			}
			
			ans+=maxa;
		}
		for(int j=1;j<=3;j++){
			
			if(p[j]>n/2){
				
				
				for(int i=1;i<=n;i++){
					
					if(wh[i][j]){
					
						dd[++t]=d[i];
											
					}
					
				}
				
				sort(dd+1,dd+t+1);
				
				for(int i=1;i<=p[j]-n/2;i++){
					
					
					ans-=dd[i];
					
					
				}
				
			}
			
		}
		
		cout << ans << '\n';
		
		
		
		
	}
	
	return 0;

}
