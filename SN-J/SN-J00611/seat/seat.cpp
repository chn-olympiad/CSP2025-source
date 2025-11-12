#include<bits/stdc++.h>
using namespace std;
int a[10000],n,m;
int b[10000][10000];

struct b {
	int x;
	int y;
	int mn;
} e[100000];
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		//cout<<a[i]<<" ";
	}
	int mi=a[1];
	cout<<endl;
	sort(a+1,a+1+n*m);

	int x=1,y=1;
	int n1=0;
	bool l=1;
	for(int i=n*m;i>=1;i--){
	
	
		if(n1<=n){
			e[i].x=x;
			e[i].y=y;
			e[i].mn=a[i];
			cout<<y<<" ";
			//cout<<e[i].mn<<" ";
		}
		n1++;	
		if(l=1&&n1<n)
		{
		y++;
		}	
		 else if(l==0&&n1<n)
		{
			y--;
		}
		
		 if(n1==n&&l==0){
			x++;
			l=1;
			n1=0;
		}
		  else if(n1==n&&l==1){
			x++;
			l=0;
			n1=0;
		}	

	//	cout<<x<<" "<<y<<endl;
	//cout<<e[i].mn<<" ";
	}
	for(int i=n*m;i>=1;i--){
		if(e[i].mn==mi){
			cout<<e[i].x<<" "<<e[i].y;
			break;
		}
	}
	return 0;
}
