#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,s,w,c,r,score[105],t=0;
	cin>>n>>m;
	for (int i=1;i<=m*n;i++){
		cin>>score[i];
		if(i==1) s=score[i];
	}
	
	for (int i=1;i<=m*n;i++){
		if(score[i]>t) {
			t=score[i];
			score[i]=score[0];
			score[0]=t;
		}
	}
	for (int i=0;i<m*n;i++){
		if (score[i]==s) w=i+1;
	}
	int b=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (i*n+j==w) cout<<i<<' '<<j+1;
			b++;
		}
	}
	return 0;
}
