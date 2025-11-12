#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],flag=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	flag=a[1];
	sort(a+1,a+(n*m)+1);
	int r=1,c=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==flag){
			cout<<c<<" "<<r;
			break;
		} 
		if(((c&1) && (r!=n)) || (!(c&1) && (r!=1))){
			if(c&1) r++;
			else r--;
		}else c++;
	}

	return 0;
}

