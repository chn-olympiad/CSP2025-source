#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int a[N];
bool cmp(int b,int c){
	return b>c;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int R_score;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}
	R_score=a[1];
	int x=(n*m);
	sort(a+1,a+x+1,cmp);
//	for(int i=1;i<=x;i++){
//		cout<<a[i]<<" ";
//	}
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[k]==R_score){
					cout<<i<<" "<<j;
					k++;
					break;
				}
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[k]==R_score){
					cout<<i<<" "<<j;
					k++;
					break;
				}
				k++;
			}
		}
	}
	return 0;
}
