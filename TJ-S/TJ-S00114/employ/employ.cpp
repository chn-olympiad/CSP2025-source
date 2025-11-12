#include<iostream>
#include<algorithm>
using namespace std;
char s[505];
int c[505];
int n,m;
long long mub(long long t,long long b){
	if(t<=b){
		return b;
	}
	return t*mub(t-1, b)%998244353;
}
long long dfs(int r[12], int q, int k){
	long long z=0;
	cout << z << ' ' << r[0] << ' ' << r[1] << ' ' << q << ' ' << k << ';';
	if(n-k<m){
		return 0;
	}
	if(r[0]==1){
		if(n-k>m){
			return 1;
		}
		else if(r[1]>q && s[n]=='1'){
			return 1;
		}
		else{
			return 0;
		}
	}
	for(int i=1;i<=r[0];i++){
		if(r[i]>q && s[n-r[0]]=='1'){
			swap(r[i],r[r[0]+1]);
			int r2[11] = {r[0]-1,r[1],r[2],r[3],r[4],r[5],r[6],r[7],r[8],r[9],r[10]};
			z += dfs(r2, 0, k);
			swap(r[i],r[r[0]+1]);
		}
		else{
			swap(r[i],r[r[0]+1]);
			int r2[11] = {r[0]-1,r[1],r[2],r[3],r[4],r[5],r[6],r[7],r[8],r[9],r[10]};
			z += dfs(r2, q+1, k+1);
			swap(r[i],r[r[0]+1]);
		}
	}
	return z;
}
int main(){
	long long a=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool f=1;
	cin >> n >> m >> s;
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	if(m==n){
		for(int i=0;i<n;i++){
			if(c[i]==0 || s[i]=='0'){
				cout << 0;
				return 0;
			}
		}
		cout << mub(n, 1);
		return 0;
	}
	if(n<=10){
		int r2[11] = {n,c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],c[9]};
		cout << dfs(r2, 0, 0);
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			f = 0;
		}
	}
	if(f==1){
		sort(c,c+n+1);
		for(int i=0;i<n;i++){
			if(c[i]==0){
				a++;
			}
		}
		if(a > m){
			cout << 0;
		}
		else{
			cout << mub(n, 1);
		}
		return 0;
	}
	return 0;
}
