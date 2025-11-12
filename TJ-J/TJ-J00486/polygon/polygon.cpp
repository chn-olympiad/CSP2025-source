#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1000005];
int cnt;
int b[25];
void dfs(int x,int s){
	if(s==x+1){
		int maxn=-1,sum=0;
		for(int i=1;i<=x;i++){
			maxn=max(maxn,b[i]);
			sum+=b[i];
		}
		if(sum>maxn*2){
			cnt++;
			return;
		}
	}
	for(int i=s;i<=n;i++){
		if(a[i]>b[s-1]){
			b[s]=a[i];
			dfs(x,s+1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)dfs(i,1);
	cout<<cnt;
	return 0;
}
