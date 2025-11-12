#include<bits/stdc++.h>
using namespace std;
const int MX=1e3+29;
int a[MX];
int n,m,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int l=a[1];
	sort(a+1,a+k+1,cmp);
	int r=0;
	for(int i=1;i<=k;i++){
		if(a[i]==l){
			r=i;
			break;
		}
	}
	int y=r/n;
	if(r%n!=0)y++;
	r%=n;
	int x=0;
	if(r==0)r=n;
	if(y%2==0)x=m-r+1;
	else x=r;
	cout<<y<<" "<<x;
	return 0;
} 
