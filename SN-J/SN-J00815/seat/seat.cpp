#include<bits/stdc++.h>
using namespace std;

int test[101] = {0},t;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	for(int i = 0;i<m*n;i++){
		if(i == 0){
			cin>>a;
			test[a]++;
		}else{
		cin>>t;
		test[t]++;
		}
	}
	int asd = n*m;
	int s[asd+1];
	for(int i = 0;i<101;i++){
		for(int j = n*m;j>0;j--){
			if(test[i] == 1){
				s[j] = i;
			}
		}
	}
	int seat[n][m] = {0};
	int sn = 0,sm = 0;
	for(int i = 1;i<=m*n;i++){
		seat[sm][sn] = i;
		if(sn%2==1&&sm!=0){
			sm--;
		}else if(sn%2==0&&sm == n-1){
			sn++;
		}else if(sn%2==1&&sm == 0){
			sn++;
		}else if(sn%2==0&&sm!=m-1&&sn!=0){
			sm++;
		}
		if(sn==0&&sm!=m-1){
			sm++;
		}
		cout<<sn<<" "<<sm<<endl;
	}
	int abc;
	for(int i = 1;i<=asd;i++){
		if(s[i] == a) abc = i;
	}
	for(int i= 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(seat[i][j] == abc) cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
} 
