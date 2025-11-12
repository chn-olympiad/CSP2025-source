#include<iostream>
#define MAXN 5005
using namespace std;

int n;
int a[MAXN];
int ans=0;
int maxs;
int sum;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n;
	return 0; 
}
