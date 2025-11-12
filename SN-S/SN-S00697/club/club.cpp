#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,n; 
int maxx;
int cnt,f[5];
int f1[5];

struct edge{
	int x,y,z;
}a[100005];

void dfs(int x,int sum){
	if(x==n){
		if(f[1]<n/2){
			maxx=max(maxx,sum+a[x].x);
		}
		if(f[2]<n/2){
			maxx=max(maxx,sum+a[x].y);
		}
		if(f[3]<n/2){
			maxx=max(maxx,sum+a[x].z);
		}
		return;
	}else{
		if(f[1]<n/2){
			f[1]++;
			dfs(x+1,sum+a[x].x);
			f[1]--;
		}
		if(f[2]<n/2){
			f[2]++;
			dfs(x+1,sum+a[x].y);
			f[2]--;
		}
		if(f[3]<n/2){
			f[3]++;
			dfs(x+1,sum+a[x].z);
			f[3]--;
		}
	}
	
}

bool cmp(edge x,edge y){
	return x.x>y.x;
}

signed main(){
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		int fa=1,fb=1,fc=1;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(f,0,sizeof(f1));
		maxx=-1;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		for(int i=1;i<=n;i++){
			if(a[i].y!=0||a[i].z!=0){
				fa=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].z!=0){
				fb=0;
			}
		}
		if(fa==1){
			int sum1=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) sum1+=a[i].x;
			cout << sum1 << '\n';
		}else if(fb==1){
			int sum2=0;
			for(int i=1;i<=n;i++){
				if(a[i].x>a[i].y&&f1[1]<=n/2){
					sum2+=a[i].x;
					f1[1]++;
				}
				else if(f1[2]<=n/2){
					sum2+=a[i].y;
					f1[2]++;
				}
			}
			cout << sum2 << '\n';
		}
		else{
			dfs(1,0);
			cout << maxx << '\n';	
		}
		
	}
	return 0;
}
//dp疑似 
//蒸一下正解
//难绷完了
//预备afo嘻嘻 
//surf是对的 
