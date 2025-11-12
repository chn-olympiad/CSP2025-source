#include <bits/stdc++.h>
#define pb push_back
#define pii std::pair<int,int>
#define ll long long
#define vi std::vector<int>
/*Calm down*/
using namespace std;
ll a[100100][3];
ll ans[100100][3];
ll cho[100100];
void slove(){
	int n; scanf("%d",&n);
	ll alpha= 0, beta = 0,tans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
		ans[i][0] = std::max(a[i][0],std::max(a[i][1],a[i][2]));
		ans[i][2] = std::min(a[i][0],std::min(a[i][1],a[i][2]));
		ans[i][1] = a[i][0] + a[i][1] + a[i][2] - ans[i][0] - ans[i][2];
		ans[i][2] -= ans[i][0];
		ans[i][1] -= ans[i][0];
		if(ans[i][0] == a[i][0]) alpha ++ ,tans += ans[i][0],cho[i]=0;
		else if(ans[i][0] == a[i][1]) beta ++ ,tans += ans[i][0],cho[i]=1;
		else tans += ans[i][0],cho[i]=2;
	}
	int pn = (n/2);
	if(alpha > pn || beta > pn || (n-beta-alpha) > pn){
		ll hs = std::max(std::max(alpha-pn,beta-pn),n-beta-alpha-pn);
		ll toc = -1;
		if(hs == alpha - pn) toc = 0;
		else if(hs == beta -pn) toc = 1;
		else toc = 2;
		
		std::vector<ll>pr;
		for(int i = 1 ; i <= n ; ++ i){
			if(cho[i] == toc){
				pr.pb(ans[i][1]);
			}
		}
		std::sort(pr.begin(),pr.end());
		int pz = pr.size();
		for(int i =pz - 1 ; hs;hs--,i--){
			
			tans += pr[i];
		}
	}
	printf("%lld\n",tans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t ; scanf("%d", &t);
	while(t --) slove();
	return 0;
}
