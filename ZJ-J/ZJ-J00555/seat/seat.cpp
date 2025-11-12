#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int get(int k){
	if(k==0) return n;
	return k;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		cnt+=(a[i]>a[1]);
	}
	cnt++;
	int f;
	if(cnt%n==0) f=cnt/n;
	else f=cnt/n+1;
	if(f%2) cout<<f<<" "<<get(cnt%n);
	else cout<<f<<" "<<n-get(cnt%n)+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
problem seter,why do you don't give me big data?
he yi wei?
*/

