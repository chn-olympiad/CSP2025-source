#include<bits/stdc++.h>
using namespace std;
int n,m,k,x=1,y=1,z=1,s,a[101];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++)
	    cin>>a[i];
	k=a[1];
	sort(a+1,a+s+1);
	for(int i=s;i>=1;i--){
	    if(a[i]==k){
			cout<<x<<" "<<y;
			return 0;
		}
		if((x%2==1&&y==n)||(x%2==0&&y==1)){
			x++;
			z*=-1;
		}
		else y+=z;
		
	}
	return 0;
}
