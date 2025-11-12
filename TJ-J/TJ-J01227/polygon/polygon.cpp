#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int m,a[100];
    cin>>m;
    for(int i=0;i<m;i++){
    	cin>>a[i]; 
    	for(int i=3;i<=m;i++){
    		if((a[i]+a[i+1]+a[i+m])/2<m){
    			cout<<3;
    			return 0;
			}
		}
	}
    cout<<4||5;
    return 0;
}

