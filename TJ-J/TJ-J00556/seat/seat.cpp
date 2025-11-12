#include<bits/stdc++.h>
using namespace std;
int l[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>l[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(l[j]>l[i]){
				swap(l[j],l[i]);
				if(i==s){
					s=j;
				}
			}
		}
	}
	s+=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s--;
			if(s==0){
				if(i%2==0){
					cout<<i<<" "<<j+m/2;
				}else{
					cout<<i<<" "<<j;
				}
				return 0;
			}
		}
	}
	return 0;
}
