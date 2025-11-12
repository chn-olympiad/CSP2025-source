#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int grade[106],mapp[16][16];
bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) 
		cin >> grade[i];
	int litteR=grade[1];
	sort(grade+1,grade+1+n*m);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				int k=(i-1)*n+j;
				mapp[i][j]=grade[k];
				//cout << mapp[i][j] << " ";
			}
		}
		else{
			for(int j=n;j>=1;j--){
				int k=(i-1)*n+j;
				mapp[i][j]=grade[k];
				//cout << mapp[i][j] << " ";
			}
		}
		//cout << "\n";
	}
	int posx=0,posy=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mapp[i][j]==litteR){
				posx=i,posy=j;
			}
		}
	}
	cout << posy <<" "<<posx;
	return 0;
}

