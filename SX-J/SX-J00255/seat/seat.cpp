#include<bits/stdc++.h>
using namespace std;
int zhuo[10][10];
int shu[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l_l;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>shu[i];
	}l_l=shu[0];
	sort(shu,shu+n*m);
	int su=n*m-1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			zhuo[i][j]=shu[su];
			su--;
		}
		if(i<m){
			i++;
			for(int j=n-1;j>=0;j--){
				zhuo[i][j]=shu[su];
				su--;
			}
		}

	}for(int i=0 ;i<n;i++){
		for(int j=0;j<m;j++){
			if(zhuo[j][i]==l_l){
				cout<<j+1<<" "<<i+1;
				return 0;
			}

		}
	}
	return 0;
}