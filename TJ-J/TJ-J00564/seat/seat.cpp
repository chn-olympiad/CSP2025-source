#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m,c,r,max=0,R;
	int seat2[n][m];
	cin>>n>>m;
	int s[n*m];
	for(int i=1;i<n*m;i++){
		cin>>s[i];
	}
	for(int i=1;i<n*m;i++){
		R=s[1];
		if(s[i]<s[i+1]){
			max=s[i+1];
		}
		for(int x=1;x<n;x++){
			for(int j=1;j<m;j++){
				s[1]=seat2[1][1];
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			cout<<seat2[i][j];
		}
	}
	return 0;
} 
