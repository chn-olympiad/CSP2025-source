#include <bits/stdc++.h>
using namespace std;
long long A = 0,n,m,k,xz[12],father[210005],c[12],cc[12][10005],ans = LONG_LONG_MAX;
bool us[210005];
struct node{
	long long q,z,b;
}d[2000005];
bool cmp(node x,node y){
	return x.b < y.b;
}
long long find(long long o){
	if(father[o] == o) return o;
	father[o] = find(father[o]);
	return father[o];
}
long long sum,cur,t,nw,curm,x,y,z,fx,fy;
void dfs(int s){
	if(s == k+1){
		sum = 0;cur = m;t = 0;nw = 0;curm;
		for(int i = 1;i <= 21000;i++){
			father[i] = i;
			us[i] = false;
		}
		for(int i = 1;i <= k;i++){
			if(xz[i]){
				sum += c[i];
				for(int j = 1;j <= n;j++){
					d[++cur].q = n+i;
					d[cur].z = j;
					d[cur].b = cc[i][j];
				}
			}
		}
		curm = cur;
		sort(d+m+1,d+cur+1,cmp);
		cur = m+1;
		while(t < n-1){
			nw++;
			while(d[cur].b < d[nw].b && cur <= curm){
				if(t == n-1)
					break;
				x = d[cur].q,y = d[cur].z,z = d[cur].b;fx = find(x),fy = find(y);
				if(fx != fy){
					sum += z;
					father[fy] = fx;
					if(us[x]) 
						t++;
					us[x] = true;
				}
				cur++;
			}
			x = d[nw].q,y = d[nw].z,z = d[nw].b;
			fx = find(x),fy = find(y);
			if(fx != fy){
				sum += z;
				father[fy] = fx;
				t++;
			}
		}
		ans = min(ans,sum);
		return;
	}
	dfs(s+1);
	xz[s] = 1;
	dfs(s+1);
	xz[s] = 0;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
		cin >> d[i].q >> d[i].z >> d[i].b;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		A = max(A,c[i]);
		for(int j = 1;j <= n;j++)
			cin >> cc[i][j];
	}
	if(A == 0){
		sum = 0;cur = m;t = 0;nw = 0;curm;
		for(int i = 1;i <= 210000;i++)
			father[i] = i;
		for(int i = 1;i <= k;i++){
			for(int j = 1;j <= n;j++){
				d[++cur].q = n+i;
				d[cur].z = j;
				d[cur].b = cc[i][j];
			}
		}
		sort(d+1,d+cur+1,cmp);
		while(t < n-1){
			nw++;
			x = d[nw].q,y = d[nw].z,z = d[nw].b;
			fx = find(x),fy = find(y);
			if(fx != fy){
				sum += z;
				father[fy] = fx;
				if(x > n){
					if(us[x])
						t++;
					us[x] = 1;
				}
				else
					t++;
			}
		}
		cout << sum << '\n';
	}
	else{
		sort(d+1,d+m+1,cmp);
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
