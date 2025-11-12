#include<bits/stdc++.h>

using namespace std;

const int N=105;

int n,m,nm;

int st;

int a[N];

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	
	st=a[1];
	
	sort(a+1,a+1+nm);
	
	int idx=nm+1;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				idx--;
				if(a[idx]==st){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				idx--;
				if(a[idx]==st){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	return 0;
}