#include<bits/stdc++.h>
using namespace std;
const int MAXN=1145;
int lst[MAXN],n,m,R,Rp; 
signed main(){
	freopen("seat.in","r+",stdin);
	freopen("seat.ans","w+",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>lst[i];
	}
	R=lst[1];
	sort(lst+1,lst+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
//		cout<<lst[i]<<' ';
		if(lst[i]==R){
			Rp=i;
		} 
	}
	//cout<<Rp;
	int pl=0;
	for(int i=1;i<=m;){
		for(int j=1;j<=n;j++){
			pl++;
			if(pl==Rp){
				cout<<i<<' '<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			pl++;
			if(pl==Rp){
				cout<<i<<' '<<j;
				return 0;
			}
		}
		i++;
	}
}
