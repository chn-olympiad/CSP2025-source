#include<bits/stdc++.h>;
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m],b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int s=b[0];
	sort(b,b+n*m,cmp);
	int x=0;
	for(int j=0;j<m;j++){
		
		for(int i=0;i<=n-1;i++){
			a[i][j]=b[x];
			x++;
		}
		j++;
		for(int i=n-1;i>=0;i--){
			a[i][j]=b[x];
			x++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==s)cout<<j+1<<" "<<i+1;
		}
	}
	cout<<endl;
	return 0;
}

