//SN-J01197  魏赫含  西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll k,a[N],n,sum1=0,sum2=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum1++;
			}
		}
		cout<<sum1;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum1++;
			}
			else{
				sum2++;
			}
		}
		cout<<sum2+sum1/2;;
	}
	return 0;
}
