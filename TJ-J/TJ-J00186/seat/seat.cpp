#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int s[250];
int cnt=1;
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i];
	int ans=s[1];
	sort(s+1, s+1+n*m, cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++)  a[i][j]=s[cnt++];
		}else{
			for(int i=n;i>=1;i--) a[i][j]=s[cnt++];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans){
				cout<<j<<" "<<i<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
//无聊到下雨天 今夜挫败的心情更加明显 谁来陪有着满载过多记忆的疲倦 重复着思念 
