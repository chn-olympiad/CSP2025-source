#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	long long l;
	long long r;
};
long long arr[600005],s[600005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
		s[i]=s[i-1]^arr[i];
	}
	long long p,t=1;
	node maxx;
	maxx.l=0;
	maxx.r=0;
	for(int i=1;i<=n;i++){
		for(int j=maxx.r;j<=i;j++){
			p=s[i]^s[j-1];
			if(p==k){
				if(maxx.r<j){
					cnt++;
					maxx.l=j;
					maxx.r=i;
					j=maxx.r+1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
