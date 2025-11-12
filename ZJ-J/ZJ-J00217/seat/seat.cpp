#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int R;
	int seated=1;
	cin>>R;
	for(int i=1;i<n*m;i++){
		int other;
		cin>>other;
		if(other>R) seated++;
	}
	int lt=(seated-1)/n+1; // 第几列 
	cout<<lt<<" "; 
	if(lt%2==1){//单数向下遍历 
		cout<<seated-n*(lt-1);
	}
	else{//双数向上遍历 
		cout<<n*lt-seated+1;
	}
	return 0;
}

