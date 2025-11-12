//TOO HARD!!!
//25pts

//jin nian tai nan le
//xiakule

//ovo -> owo -> ono -> awa -> pwp -> qwq

#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int a1,a2,a3;
	int no0cnt;
	int maxx;
}a[100005];
int ans;
//int f[100005][5],cnt[100005][5];
int cnt;
void dfs(int dep,int sum,int cnt1,int cnt2,int cnt3){
	cnt++;
	if(cnt1 > n/2||cnt2 > n/2||cnt3 > n/2) return;
	if(dep == n+1){
		ans = max(ans,sum);
		return;
	}
	if(cnt >= 1e8){
		cout << ans;
		exit(0);
	}
	dfs(dep+1,sum+a[dep].a1,cnt1+1,cnt2,cnt3);
	dfs(dep+1,sum+a[dep].a2,cnt1,cnt2+1,cnt3);
	dfs(dep+1,sum+a[dep].a3,cnt1,cnt2,cnt3+1);
	
}
bool cmpA(node u,node v){
	return u.a1 > v.a1;
}
bool cmpB(node u,node v){
	if(max(u.a1,u.a2) == max(v.a1,v.a2)){
		if(u.a1 == v.a1) return u.a1 < v.a1;
		else return u.a1 > v.a1;
	}else return max(u.a1,u.a2) > max(v.a1,v.a2);
//	if(u.a1 == v.a1) return u.a2 > v.a2;
//	else return u.a1 < v.a1; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
    cin >> t;
    while(t--){
    	ans = 0;
    	cin >> n;
    	bool A = 1,B = 1;
    	for(int i = 1;i <= n;i++){
    		scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
//			a[i].maxx = max(a[i].a1,a[i].a2,a[i].a3);
//			a[i].no0cnt = (a[i].a1 != 0)+(a[i].a2 != 0)+(a[i].a3 != 0);
			if(a[i].a2 != 0||a[i].a3 != 0) A = 0;
			if(a[i].a3 != 0) B = 0;
		}
		if(n <= 30){
			dfs(1,0,0,0,0);
		}else{
			if(A){
				sort(a+1,a+1+n,cmpA);
				for(int i = 1;i <= n/2;i++) ans += a[i].a1;
			}
//			}else if(B){
////				sort(a+1,a+1+n,cmpB);
////				int cnt1 = 0,cnt2 = 0;
////				for(int i = 1;i <= n;i++){
////					if(cnt1 == n/2) ans += a[i].a2,cnt2++; 
////					else if(cnt2 == n/2) ans += a[i].a1,cnt1++;
////					else{
////						if(a[i].a1 > a[i].a2) ans += a[i].a1,cnt1++;
////						else ans += a[i].a2,cnt2++; 
////					}
//////					cout << a[i].a1 << " " << a[i].a2 << endl; 
////				}
////				sort(a+1,a+1+n,cmpB);
////				for(int i = 1;i <= n/2;i++){
////					ans += a[i].a2;
////				}				
////				for(int i = n/2+1;i <= n;i++){
////					ans += a[i].a1;
////				}
//				for(int i = 1;i <= n;i++) ans += max(a[i].a1,a[i].a2); 	
//			}else{
//				memset(f,0,sizeof(f));
//				memset(cnt,0,sizeof(cnt));
//				for(int i = 1;i <= n;i++){
//					for(int j = 1;j <= 3;j++){
//						for(int k = 1;k <= 3;k++){
//							if(cnt[i-1][k] > n/2) continue;
//							f[i][j] = max(f[i][j],f[i-1][k]+a[i].a);
//						}
//					}
//				}
//			}
		}
		cout << ans << endl;
	}
}
