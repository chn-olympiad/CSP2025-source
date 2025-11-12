#include<bits/stdc++.h>
using namespace std;int a[1002];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+n*m);
	for(int i=(n*m-1);i>=0;i--){
		if(a[i]==r){
			int s=(n*m-1)-i+1;
			int h=(s-1)/n+1;
			s=(s-1)%n+1;
			if(h%2==0){
				cout<<h<<' '<<(n-s)%2+1<<endl;
			}
			else{
				cout<<h<<' '<<s<<endl;
			}
		}
		
	}
	return 0;
}