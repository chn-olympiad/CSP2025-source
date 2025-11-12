#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin >> n >> m;
	vector<int>b(n*m);
	for(int i = 0;i < n*m;i++)cin >>b[i];
	int me = b[0];
	sort(b.begin(),b.end());
	vector<int>a(n*m);
	int cnt1 = 0;
	for(int i = n*m-1;i >= 0;i--)a[cnt1++] = b[i];
	vector< vector<int> >seat(n+1,vector<int>(m+1));
	int cnt = 0;
	for(int j = 1;j <= m;j++){
		if(j %2)
			for(int i = 1;i <= n;i++)
				seat[i][j] = a[cnt++];
		else
			for(int i = n;i>= 1;i--)
				seat[i][j] = a[cnt++];	
	}
	int bestr = 0,bestc = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1; j<=m;j++){
			if(seat[i][j] == me){
				bestr = i;bestc = j;
			}
		}
	}
	cout << bestc << " "<< bestr; 
	return 0;
} 
