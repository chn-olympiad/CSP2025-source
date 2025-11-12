#include<bits/stdc++.h>
using namespace std;
int n,m,score[110],h[110],l[110],con,w=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n*m;i++){
		for(int j=1;j<=n;j++){
			con++;
			if(i%2==0) h[con]=n-j+1;
			else h[con]=j;
			l[con]=i;
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
		if(score[i]>score[1]) w++;
	}
	cout<<l[w]<<" "<<h[w];
	return 0;
}
