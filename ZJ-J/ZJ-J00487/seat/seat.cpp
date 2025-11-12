#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],st[15][15];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	int s=1,e=n,id=1;
	for(int i=1;i<=m;i++){
//		cout<<"=========1\n";
		if(s<=e){
			for(int j=s;j<=e;j++){
				st[i][j]=a[id];
				id++;
			}
		}
		else{
			for(int j=s;j>=e;j--){
				st[i][j]=a[id];
				id++;
			}
		}
		
		swap(s,e);
	}
	
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
//			cout<<st[i][j]<<" ";
			if(st[i][j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
//		cout<<"\n";
	}
	return 0;
}
