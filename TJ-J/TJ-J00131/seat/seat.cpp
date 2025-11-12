#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>=2&&a[i]>a[1]){
			num++;
		}
	}
	int lie=(num-1)/n+1;
	if(lie%2==1){
		cout<<lie<<" "<<(num-1)%n+1;
	}
	else{
		cout<<lie<<" "<<n-((num-1)%n+1)+1;
	}
	return 0;
}
