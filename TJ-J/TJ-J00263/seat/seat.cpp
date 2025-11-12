#include<bits/stdc++.h>
using namespace std;
int n,m,r=0;
int a[105];
void p(int a[],int b){
	for(int i=0;i<b-1;i++){
		for(int j=0;j<b-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				if(r==j){
					r++;
				}
				else if(r==j+1){
					r--;
				}
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	p(a,n*m);
	int h=r/n+1,l=r%n;
	if(h%2==1){
		cout<<h<<" "<<l+1;
	}
	else{
		cout<<h<<" "<<n-l;
	}
	return 0;
}
