#include<bits/stdc++.h>
using namespace std;

int n,m,k;
priority_queue<int> pq;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int gg = -1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int a;
		cin>>a;
		if(i == 1) k = a;
		pq.push(a);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(k == pq.top()){
				if(i%2 == 0){
					cout<<i<<' '<<n-j+1;
				}else{
					cout<<i<<' '<<j;
				}
				return 0;
			}
			pq.pop();
		}
	}
	return 0;
}
