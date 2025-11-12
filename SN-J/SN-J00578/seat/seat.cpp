#include<bits/stdc++.h>;
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int a,s[100],w;
	cin>>w;
	s[0]=w;
	int cnt=0;
	for(int i=1;i<n*m;i++){
		cin>>a;
		s[i]=a;
	}
	for(int i=1;i<n*m;i++){
		if(s[i]>s[0]) cnt++;
	}
	int x,y;
	x=(cnt+1)/n;
	y=(cnt+1)%n;
	if(x%2==0&&y!=0){
		cout<<x+1<<" "<<y;
	}
	if(x%2==0&&y==0){
		cout<<x<<" "<<1;
	}
	if(x%2==1&&y==0){
		cout<<x<<" "<<n;
	}
	if(x%2==1&&y!=0){
		cout<<x+1<<" "<<n-y+1;
	}
	return 0;
}
