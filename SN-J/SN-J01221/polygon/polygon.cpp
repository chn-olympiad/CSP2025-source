/*龚逸宸 SN-J01221 西安市曲江第一学校 */
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){
		long long maxx=max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>2*maxx){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
