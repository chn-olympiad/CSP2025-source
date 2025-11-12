#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct M{
	int id;
	int m;
	int z;
}a[N];
bool iusd[N];
int zb[N];
int ans=0;
int t,rt=0,rm;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	memset(iusd,0,sizeof(iusd));
	cin >> t;
	while(t){
		cin >> n;
		int p=n/2;
		for(int i=0;i<=3*n-1;++i){
			cin >> a[i].m;
			a[i].id=i/3+1;
			a[i].z=i%3+1;
		}
		for(int j=1;j<=n*3;++j){
			for(int i=1;i<=n*3;++i){
				if(a[i].m<a[i+1].m){
					swap(a[i],a[i+1]);
				}
			}
		}
		for(int j=1;j<=3*n;++j){
			rt=0;
			rm=n;
			for(int i=0;i<3*n;++i){
				iusd[a[i].id]=false;
				zb[i]=0;
			}
			for(int i=0;i<=3*n-1;++i){
				if(rm==0){
					ans=max(ans,rt);
					break;
				}	
				if(!iusd[a[i].id]){
					rt+=a[i].m;
					zb[a[i].z]++;
					iusd[a[i].id]=true;
					rm--;
				}else{
					continue;
				}
				for(int i=1;i<=3;++i){
					if(zb[i]>p){
						break;
					}
				}
			}
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}
