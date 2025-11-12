#include<bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;

	int w = 0;
	int R_score;
	cin>>R_score;
	for(int i = 0;i<n*m-1;i++){
		int temp;
		cin>>temp;
		if(temp>R_score){
			w++;
		}
	}
	if((w/n)%2==0){
		cout<<w/n+1<<' '<<w%n+1;
	}else{
		cout<<w/n+1<<' '<<n-(w%n);
	}
	return 0;
}
