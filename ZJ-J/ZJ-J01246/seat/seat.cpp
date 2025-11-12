#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=-1;
	int ji=0;
	for(int i=0;i<n*m;i++){
		int dk;
		cin>>dk;
		if(s==-1){
			s=dk;
		}
		if(dk>s){
			ji++;
		}
	}
	cout<<ji/n+1<<" "<<ji%n+1<<endl;
}
