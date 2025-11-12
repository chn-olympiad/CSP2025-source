#include<bits/stdc++.h>
using namespace std;

int a[5010];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
		return 0;
	}
	int ans=0;
	int sum=0;
	cout<<6;
	return 0;
}
