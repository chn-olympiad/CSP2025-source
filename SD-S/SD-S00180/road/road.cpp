#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int sum=0;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		sum+=c;
	}
	cout<<sum;
	return 0;
} 
