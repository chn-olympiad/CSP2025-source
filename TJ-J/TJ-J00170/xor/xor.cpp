#include<bits/stdc++.h>
using namespace std;
int n,k,len=0,ans=0;
int a[1001];
int dp[1001][1001];
struct node{
	int x,y;
}s[1000001];
bool cmp(node g,node o){
	if(g.y==o.y){
		return g.x<o.x;
	}
	return g.y<o.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=a[i];
		if(a[i]==k){
			s[++len].x=i;
			s[len].y=i;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j+i<=n;j++){
			dp[j][j+i]=(dp[j][j]^dp[j+1][j+i]);
			if(dp[j][j+i]==k){
			    s[++len].x=j;
				s[len].y=j+i;
			}
		}
	}
	sort(s+1,s+len+1,cmp);
	int zx=0;
	for(int i=1;i<=len;i++){
		//cout<<s[i].x<<" "<<s[i].y<<endl;
		if(s[i].x>zx){
			ans++;
			zx=s[i].y;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
