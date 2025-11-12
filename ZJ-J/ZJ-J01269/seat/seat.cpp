#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
   	int n,m,ji;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	} 
	ji=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=0;
	for(int i = 1;i<=n;i++){
	    for(int j = 1;j<=m;j++){
	    	c++;
	    	if(a[c]==ji){
	    		cout<<i<<" "<<j;
	    		return 0;
			}
		}
		i++;
		if(i>n)break;
		for(int j = m;j>=1;j--){
			c++;
			if(a[c]==ji){
	    		cout<<i<<" "<<j;
	    		return 0;
			}
		}
	}
	return 0;
} 
