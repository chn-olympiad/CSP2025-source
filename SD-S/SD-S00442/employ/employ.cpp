#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int n,m;

int s[N];
int c[N];
int vis[N];
int ans;
int sit[N];
bool check(){
	int num = 0;//Î´Íê³ÉµÄ
	int suc = 0;
	for(int i = 1;i<=n;i++){
		if(num>=c[sit[i]]){
			num++;
			continue;
		}
		if(c[i] == 0){
			num++;
			continue;
		}
		suc++;
	} 
	if(suc>=m) return true;
	return false;
}
void dfs(int x){
	if(x >n){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		sit[x] = i;
		dfs(x+1);
		vis[i] =0;
	}
}





int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		char c;
		c = getchar();
//		while(c == ' ') c = getchar();
		s[i] = c-'0';
//		cout<<s[i];
	}
	for(int j = 1;j<=m;j++){
		scanf("%d",&c[j]);
	}
	
	dfs(1);
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
