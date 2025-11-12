#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
const int INF = 0x3f3f3f3f;
struct sum{
	int a,mb,club;
}num[MAXN*3];
int cnt_club[MAXN*3];
bool in_mb[MAXN*3];
int n,cnt,ans,a[MAXN][4];
bool cmp(sum x,sum y){
	return x.a > y.a;
}
int dfs(int q,int w,int anss){
	if(q == (n)){
		return a[q][w];
	}
	int tot=anss;
	if(cnt_club[w] + 1 < (n/2)){
		cnt_club[w]++;
		for(int i=1;i<=3;i++){
			tot=max(tot,dfs(++q,i,anss));
			q--;
		}
		cnt_club[w]--;
	}else{
		return -INF;
	}
	anss = anss+tot;
	return anss;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(cnt_club,0,sizeof cnt_club);
		memset(in_mb,0,sizeof in_mb);
		int xz = 0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>num[++cnt].a;
				a[i][j] = num[cnt].a;
				num[cnt].mb = i;
				num[cnt].club = j;
				if(num[cnt].a != 0 && (j == 2 || j == 3)){
					xz = 1;
				}
			}
		}
		if(xz == 0){//只有一列有数 
			sort(num+1,num+1+n*3,cmp);
		
			for(int i=1;i<=(n/2);i++){
				
				ans += num[i].a;
			}
		}
		if(xz == 1 ){
			sort(num+1,num+1+n*3,cmp);
			if(n == 2){
				for(int i=1;i<=(n*3);i++){
					for(int j=1;j<=(n*3);j++){
						if(i != j){
							if(num[i].mb != num[j].mb && num[i].club != num[j].club){
								ans = max(ans,num[i].a + num[j].a);
	
							}
						}
					}
				}
			}else{
				for(int i = 1;i<=3;i++){
					ans = max(ans,dfs(1,1,0));
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
} 
