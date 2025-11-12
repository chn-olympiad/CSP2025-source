#include <bits/stdc++.h>
using namespace std;
long long n,a[5001],b[5001],cnt=0;
long long dfs(long long y,long long l,long long cnt,int c){
	long long x = 1;
	for(int i = l;i>=0;i--){
		if(cnt+b[i]*c > 2*b[y]) x+=dfs(y,i,cnt+b[i]*c,0-c);
	}
	return x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a[0]=0;
	b[0]=0;
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(long long i =1;i<=n;i++){
		b[i] = a[i]+b[i-1];
		if(i>=3){
			if(b[i] <= 2*a[i]) continue;
			cnt++;
			for(long long r=1;r<i;r++){
				for(long long l=r-1;l>=0 and i-r+l>=3;l--){
					cout << b[i]-b[r]+b[l]<<":" <<a[i]<<" "<<l << ":"<<r<<endl;
					if(b[i]-b[r]+b[l] > 2*a[i]){
						cnt+= dfs(i,l,b[i]-b[r]+b[l],-1);
						cnt %= 998244353;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
