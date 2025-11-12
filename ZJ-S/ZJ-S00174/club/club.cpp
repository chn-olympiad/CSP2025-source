#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Data{
	int x,y,z;
}a[N];
int cnt,cnt1,cnt2;
int main(){
	freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t -- ){
		cnt = cnt1 =cnt2 = 0;
		int n;
		cin>>n;
		
		
		int pov = n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		long long ans = 0;
		for(int i=1;i<=n;i++){
	    	int yi = max(a[i].x,max(a[i].y,a[i].z));
	    	if(yi == a[i].x){
	    		if(cnt<=pov){
	    			ans+=yi;
	    			cnt++;
	    			continue;
				}else{
					int er = max(a[i].y,a[i].z);
					if(er == a[i].y){
						if(cnt1<=pov){
							ans+=er;
							cnt1++;
							continue;
						}else{
							ans+=a[i].z;
							cnt2++;
							continue;
						}
					}
				}
			}
			 if(yi == a[i].y){
				if(cnt1<=pov){
	    			ans+=yi;
	    			cnt1++;
	    			continue;
				}else{
					int er = max(a[i].x,a[i].z);
					if(er == a[i].x){
						if(cnt<=pov){
							ans+=er;
							cnt++;
							continue;
						}else{
							ans+=a[i].z;continue;
							cnt2++;
						}
					}
				}
			}
			 if(yi == a[i].z){
				if(cnt2<=pov){
	    			ans+=yi;
	    			cnt2++;
	    			continue;
				}else{
					int er = max(a[i].y,a[i].x);
					if(er == a[i].y){
						if(cnt1<=pov){
							ans+=er;
							cnt1++;
							continue;
						}else{
							ans+=a[i].x;continue;
							cnt++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	
	}

	return 0;
}
