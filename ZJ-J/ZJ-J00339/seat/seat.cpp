#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool sb(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int k=a[0];
	sort(a,a+n*m,sb);
	for(int i=0;i<n*m;i++){
		if(a[i]==k){
			k=i;
			k++;
			break; 
		}
	}
	int x,y;
	x=k/n;
	y=k%n;
	if(y!=0) x++;
	else y=n;
	if(x%2==0) y=n-y+1;
	cout<<x<<' '<<y;
	return 0;
	
	
	
	
}
