#include<bits/stdc++.h>
using namespace std;
struct pp{
	int x,y;
}b[10001];
int n,m,a[10001],ans,t,s[10001];
bool cmp(pp x,pp y){
	return x.y < y.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = s[i-1]^a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int v = s[j]^s[i-1];
			if(v == m)b[++t].x = i,b[t].y = j;
		}
	}
	sort(b+1,b+t+1,cmp);
	int ly = 0;
	for(int i = 1;i <= t;i++){
		if(b[i].x > ly){
			ans++;
			ly = b[i].y;
		}
	}
	cout << ans;
	return 0;
} 
