#include<bits/stdc++.h>
using namespace std;
int n,m,z;
int a[1001];
int c,r;
bool cmp(int a,int b){
	if(a>b){
		return 1;
	}
	else{
		return 0;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		z=a[1];	
	}
	sort(a+1,a+m*n,cmp);
	for(int i=1;i<=m*n;i++){
		for(int i=1;i<=n;i++){
			r++;
			if(a[i]==z){
				cout<<c<<" "<<r;
				break;
			}
		}
		c++;
		if(a[i]==z){
			cout<<c<<" "<<r;
			break;
		}
		for(int i=n;i>=1;i--){
			r--;
			if(a[i]==z){
				cout<<c<<" "<<r;
				break;
			}
		}
		c++;
		if(a[i]==z){
			cout<<c<<" "<<r;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
