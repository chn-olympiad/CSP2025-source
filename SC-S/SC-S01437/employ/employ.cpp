#include<iostream> 
#include<cstdio> 
#include<algorithm>
#include<cmath>
using namespace std;
int m,n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
} 