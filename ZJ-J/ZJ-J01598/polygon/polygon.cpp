#include<bits/stdc++.h>
using namespace std;
long long a[100100],s,n,b[100100],book[100100];
bool check(long long k){
	long long sum,maxs=sum=0;
	for(int i=1;i<=k;i++){
		sum+=b[i];
		maxs=max(maxs,b[i]);
	}
	return sum>maxs*2;
}
long long dfs(long long x,long long y,long long z){
	if(x==y+1){
		if(check(y)) return 1;
		return 0;
	}
	long long cnt=0;
	for(int i=z+1;i<=n;i++)
		if(!book[i]){
			book[i]=1;
			b[x]=a[i];
			cnt+=dfs(x+1,y,i);
			book[i]=0;
		}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++) s+=dfs(1,i,0);
	cout<<s;
}
