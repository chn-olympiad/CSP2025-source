#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100]={},n,m,z;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	z=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==z){
			int x=i/n,y=i%n;
			if(x%2){
				cout<<x+1<<' '<<n-y+1<<endl;
				return 0;
			}
			cout<<x+1<<' '<<y+1<<endl;
		}
	}
}