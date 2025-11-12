#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[1000001][10];
int c[1000001];
int d[1000001];
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		cin >> n;
		
		
		
		for (int i = 1; i <= n; i++){
			int b;
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
				
			}
			b=max(a[i][1],max(a[i][2],a[i][3]));
			if (b==a[i][1])c[i]=1;
			else if (b==a[i][2])c[i]=2;
			else c[i]=3;
			ans+=a[i][c[i]];
		}
		int cnt1=0,cnt2=0,cnt3=0;
		for (int i = 1; i <= n; i++){
			if (c[i]==1)cnt1++;
			else if (c[i]==2)cnt2++;
			else cnt3++;
		}
		if ((cnt1<=n/2)&&(cnt2<=n/2)&&(cnt3<=n/2)){
			cout << ans<<endl;;
		}
		
		
		
		
		else{
			
			if (cnt1>n/2){
				for (int i = 1; i <= n; i++){
					if ((a[i][1]-max(a[i][2],a[i][3]))<0)d[i]=618000000;
					else d[i]=a[i][1]-max(a[i][2],a[i][3]);
				}
				sort(d+1,d+n+1);
				for (int i =1; i<= cnt1-n/2;i++)ans-=d[i];
			}
			
			
			
			
			
			else if (cnt2>n/2){
				for (int i = 1; i <= n; i++){
					if ((a[i][2]-max(a[i][1],a[i][3]))<0)d[i]=618000000;
					else d[i]=a[i][2]-max(a[i][1],a[i][3]);
				}
				sort(d+1,d+n+1);
				for (int i =1; i<= cnt2-n/2;i++)ans-=d[i];
				
			}
			
			
			
			
			
			else{
				for (int i = 1; i <= n; i++){
					if ((a[i][3]-max(a[i][2],a[i][1]))<0)d[i]=618000000;
					else d[i]=a[i][3]-max(a[i][2],a[i][1]);
				}
				sort(d+1,d+n+1);
				for (int i =1; i<= cnt3-n/2;i++)ans-=d[i];
			}
			
			
			
			
			
			cout << ans<<endl;
		}
	}
	return 0;
}
