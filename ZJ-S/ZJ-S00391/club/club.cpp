#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
const Int MaxN = 2e5+10;
Int t, n;
Int cheat1 = 0;
Int cheat2 = 0;
Int res = 0;;
struct uu{
	Int x, y, z;
};
uu a[MaxN];
Int Min(uu a){
	return min(a.x,min(a.y,a.z));
}
bool cmp(uu a, uu b){
	return a.x+a.y+a.z>b.x+b.y+b.z;
}
void dfs(Int p, Int cnt, Int x, Int y, Int z){
	if(p > n){
		res = max(res, cnt);
		return;
	}
	if(x < n/2){
		dfs(p+1,cnt+a[p].x,x+1,y,z);
	}
	if(y < n/2){
		dfs(p+1,cnt+a[p].y,x,y+1,z);
	}
	if(z < n/2){
		dfs(p+1,cnt+a[p].z,x,y,z+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld", &t);
	
	while(t --){
		scanf("%lld", &n);
		Int cnt = 0;
		for(Int i = 1; i <= n; i ++){
			scanf("%lld %lld %lld", &a[i].x, &a[i].y, &a[i].z);
			Int zz = Min(a[i]);
			a[i].x -= zz;
			a[i].y -= zz;
			a[i].z -= zz;
			//cout << ".." << a[i].x << " " << a[i].y << " " << a[i].z << endl;
			cnt += zz;
			cheat1 += a[i].y;
			cheat2 += a[i].z;
		}
		res = 0;
		//cout << cnt << endl;
		
		if(n <= 13){
			dfs(1,0,0,0,0);
			printf("%lld\n", res+cnt);
		} else if(cheat1 == 0 && cheat2 == 0){
			//cout << "c1\n";
			for(Int i = 1; i <= n/2; i ++){
				res += a[i].x;
			}
			printf("%lld\n", res+cnt);
		} else if(cheat2 == 0){
			//cout << "c2\n";
			sort(a+1,a+n+1,cmp);
			for(Int i = 1; i <= n; i ++){
				Int tmp = min(a[i].x,a[i].y);
				res += tmp;
				a[i].x-=tmp;
				a[i].y-=tmp;
			}
			sort(a+1,a+n+1,cmp);
			Int x = 0, y = 0;
			for(Int i = 1; i <= n; i ++){
				if(a[i].x > a[i].y && x < n/2){
					res += a[i].x;
					x ++;
				} else if(y < n/2){
					res += a[i].y;
					y ++;
				} else {
					res += a[i].x;
					x ++;
				}
			}
			printf("%lld\n", res+cnt);
		} else {
			
			for(Int i = 1; i <= n; i ++){
				res += max(a[i].x,max(a[i].y,a[i].z));
			}
			printf("%lld\n",res+cnt);
		}
		
	}
	
	
	
	//sort(a+1,a+n+1);
	
	return 0;
}

