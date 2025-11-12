#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a[105],n,m,b[105],fzq=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			b[fzq]=a[i][j];
			fzq++;
		}
	}
	int x=b[0];
	sort(b,b+fzq);
	for(int i=0;i<n;i++){
		if(c=b[i]){
			c=fzq-i;
		}
		
	}
	
	
	return 0;
}
