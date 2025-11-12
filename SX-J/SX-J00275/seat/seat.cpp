#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,cj;
    cin>>n,m;
    cj=n*m;
    for(int i=1;i<=cj;i++)
    {
    	cin>>a[i];
    	if(a[i]<a[i+1])
    	cout<<n<<" "<<m+1;
	}
	return 0;
}