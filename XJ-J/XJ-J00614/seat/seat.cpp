#include<bits/stdc++.h> 

using namespace std;

int s[10][10];
int m,n=0,c=0,r=0,mine=0,temt=0;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>m>>n;
	cout<<endl;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
	}
	
	mine=s[1][1];
	
    return 0;
}
