#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N];
bool cmp(int A,int B){
	return A>B;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[id]==p){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
				id++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[id]==p){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
				id++;
			}
		}
	}
	return 0;
}
