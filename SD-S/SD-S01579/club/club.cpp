#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+(c^48);
		c=getchar();
	}
	return res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar((x%10)^48);
}
const int N=1e5+666;
struct node{
	int a,b,c;
}arr[N];
int n,ans;
vector<int>vec[3];
void solve(){
	n=read();
	ans=0;
	vec[0].clear();vec[1].clear();vec[2].clear();
	for(int i=1;i<=n;++i){
		arr[i].a=read();
		arr[i].b=read();
		arr[i].c=read();
		if(arr[i].a>=arr[i].b&&arr[i].a>=arr[i].c){
			ans+=arr[i].a;
			vec[0].push_back(min(arr[i].a-arr[i].b,arr[i].a-arr[i].c));
		}else if(arr[i].b>=arr[i].a&&arr[i].b>=arr[i].c){
			ans+=arr[i].b;
			vec[1].push_back(min(arr[i].b-arr[i].a,arr[i].b-arr[i].c));
		}else{
			ans+=arr[i].c;
			vec[2].push_back(min(arr[i].c-arr[i].a,arr[i].c-arr[i].b));
		}
	}
	for(int i=0;i<=2;++i){
		if(vec[i].size()>n/2){
			int cnt=vec[i].size()-n/2;
			sort(vec[i].begin(),vec[i].end());
			for(int j=0;j<cnt;++j){
				ans-=vec[i][j];
			}
		}
	}
	print(ans);putchar('\n');
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
