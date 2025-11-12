#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=0,j=1;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
		s=max(a[i],a[i+1])-a[1];
	for(int i=1; i<=s; i++){
		j++;
			if(j>n){
				j--;
				i++;
                if(i==1){
                   continue;
				}
		    }
		    if(i==s){
		    	cout<<i<<" "<<j;
		    	break;
			}
			j--;
        }
    }
	return 0;
}