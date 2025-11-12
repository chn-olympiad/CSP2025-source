#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int a[100015][5] , mm[100015] , dis[100015];
void solve(){
	int n;
	int sum[5] , tot[5];
	memset(tot,0,sizeof(tot));
	memset(sum,0,sizeof(sum));
	cin >> n;
	for(int i = 1 ; i <= n  ; i ++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int mmax = max(max(a[i][1],a[i][2]),a[i][3]);
		if(mmax==a[i][1]){
			tot[1]++;
			sum[1]+=a[i][1];
			mm[i]=1;
		}
		else if(mmax==a[i][2]){
			tot[2]++;
			sum[2]+=a[i][2];
			mm[i]=2;
		}
		else{
			tot[3]++;
			sum[3]+=a[i][3];
			mm[i]=3;
		}
	}
	
	int cnt = 0 , ssum = sum[1]+sum[2]+sum[3];
	if(max(max(tot[1],tot[2]),tot[3])<=n/2){
		cout<<ssum<<"\n";
	}
	else if(tot[1]>n/2){
		for(int i = 1 ; i <= n ; i ++){
			if(mm[i]==1){
				dis[++cnt]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			}
		}
		sort(dis+1,dis+cnt+1);
		for(int i = 1 ; i <= tot[1]-(n/2) ; i ++){
			ssum-=dis[i];//cout<<"ty87	5rt6cgy9y";
		}
		cout<<ssum<<"\n";
	}
	else if(tot[2]>n/2){
		for(int i = 1 ; i <= n ; i ++){
			if(mm[i]==2){
				dis[++cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			}
		}
		sort(dis+1,dis+cnt+1);
		for(int i = 1 ; i <= tot[2]-(n/2) ; i ++){
			ssum-=dis[i];
		}
		cout<<ssum<<"\n";
	}
	else{
		for(int i = 1 ; i <= n ; i ++){
			if(mm[i]==3){
				dis[++cnt]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
			}
		}
		sort(dis+1,dis+cnt+1);
		for(int i = 1 ; i <= tot[3]-(n/2) ; i ++){
			ssum-=dis[i];
		}
		cout<<ssum<<"\n";
	}
	for(int i = 1 ; i <= n ; i ++){
		mm[i]=dis[i]=a[i][1]=a[i][2]=a[i][3]=0;
	}
	return;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
3 
4 
4 2 1 
3 2 4 
5 3 4 
3 5 1 
4 
0 1 0 
0 1 0 
0 2 0 
0 2 0 
2 
10 9 8 
4 0 0 
*/
