#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[1000010],mapp[1000010][2],dt[1000010],e,ans,fin[10003][10003];
int gogogo(int a){
	if(dt[a] == 0)
		e++;
	dt[a] = 1;
	for(int i=1;i<=n;i++){
		if(e == n)
			return ans;
		else if(dt[i] == 0 && fin[a][i] > 0){
			ans += fin[a][i];
			gogogo(i);
		}
	}
	if(e < n && )
		gogogo(a);
		
}
int main(){
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> mapp[i][0] >>mapp[i][1] >> w[i];
		fin[mapp[i][0]][mapp[i][1]] = i;
	}
	for(int i=1;i<=n;i++){
		
	}
	
}
