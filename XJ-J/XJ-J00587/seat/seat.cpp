#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int dx=n*m;
	int arr[dx];
	for(int a=1;a<=dx;a++){
		cin>>arr[a];
	}
	int mubiao=arr[1];
	sort(arr+1,arr+dx+1,cmp);
	
	for(int a=1;a<=dx;a++){
		if(arr[a]==mubiao){
			int lie=ceil(a*1.0/n);
			cout<<lie<<" ";
			if(a%n==0){
				cout<<n;
			} 
			else{
				if(lie%2==0){
					cout<<n-a%n+1;
					break;
				}
				else{
					cout<<a%n;
					break;
				}	
			}
			
		}
	}
	return 0;
}
