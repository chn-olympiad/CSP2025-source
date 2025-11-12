#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],b[N],c[N],s[N],g[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,m,ans=0;
		int ai=0,bi=0,ci=0,si=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> g[i][1] >> g[i][2] >> g[i][3];
			m = max(g[i][1],max(g[i][2],g[i][3]));//兴趣最大的那门课的兴趣值 
			if(m==g[i][1]){
				a[++ai]=i;//最感兴趣a课 
			}else if(m==g[i][2]){
				b[++bi]=i;//b课 
			}else{
				c[++ci]=i;//c课 
			}
			ans += m;//如果没有限制每课人数的最大值 
		}
		if(ai>(n/2)){//a课人数超限
			int d = ai-(n/2);//多了几人 
			for(int i=1;i<=ai;i++){//枚举放到a课的每个人 
				int tob = g[a[i]][1]-g[a[i]][2];//换到b课去兴趣值减少多少
				int toc = g[a[i]][1]-g[a[i]][3];//换到c课去兴趣值减少多少
				s[++si] = min(tob,toc);//换到减少值最少的那个 
			} 
			sort(s+1,s+si+1);//减少值从小到大排序 
			for(int i=1;i<=d;i++){
				ans -= s[i];
			}
		}else if(bi>(n/2)){//b课
			int d = bi-(n/2);
			for(int i=1;i<=bi;i++){
				int toa = g[b[i]][2]-g[b[i]][1];
				int toc = g[b[i]][2]-g[b[i]][3];
				s[++si] = min(toa,toc);
			}
			sort(s+1,s+si+1);
			for(int i=1;i<=d;i++){
				ans -= s[i];
			}
		}else if(ci>(n/2)){//c课
			int d = ci-(n/2);
			for(int i=1;i<=ci;i++){
				int toa = g[c[i]][3]-g[c[i]][1];
				int tob = g[c[i]][3]-g[c[i]][2];
				s[++si] = min(toa,tob);
			}
			sort(s+1,s+si+1);
			for(int i=1;i<=d;i++){
				ans -= s[i];
			}
		}
		cout << ans <<endl;
	}
	return 0;
}