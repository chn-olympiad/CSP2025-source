#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	if(a>b) return a>b;
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int jl=a[1];
	sort(a+1,a+n*m+1,cmp);
	int idx=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==jl){
			idx=i;
			break;
		}
	}
	if(idx<=m){
		cout << 1 << " " << m;
		return 0;
	}
	if((n%2==0&&idx+1==n*m)||(n%2!=0&&idx-1==n*m)){
		cout << n << " " << m;
		return 0;
	}
	cout << idx;
	int ans=idx%(2*m);
	if(ans>m) ans-=m;
	if((idx/m+idx%m)%2==0) cout << idx/m+idx%m << " " << ans;
	if((idx/m+idx%m)%2!=0) cout << idx/m+idx%m << " " << ans;
	
	/*3 3 94 95 96 97 98 99 100 92 93*/
	/*2 2 98 99 100 97*/
	/*2 2 99 100 97 98*/
	/*5 6 12 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1*/
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
