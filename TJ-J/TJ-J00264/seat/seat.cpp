#include<bits/stdc++.h>
#define int long long
#define cen cout << "\n"
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int ar[109];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> ar[i];
	}
	int val=ar[1];
	sort(ar+1,ar+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(ar[j*n]>val){
			continue;
		}
		if(j%2){
			int cnt=1;
			for(int i=(j-1)*n+1;i<=j*n;i++){
				if(ar[i]==val){
					cout << j << " " << cnt;
					return 0;
				}
				cnt++;
			}
		}
		else{
			int cnt=1;
			for(int i=j*n;i>=(j-1)*n+1;i--){
				if(ar[i]==val){
					cout << j << " " << cnt;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}

