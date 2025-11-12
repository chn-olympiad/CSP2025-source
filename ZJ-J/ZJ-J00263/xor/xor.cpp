#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define ull unsigned long long
using namespace std;
const int N=5e5+10;
int n,a[N],b[N];
ll k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[0]=0;
	b[1]=a[1];
	for (int i=2;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	int ans=0;
	for (int i=1,j=1;i<=n;){
		if ((b[j]^b[i-1])==k){
			ans++;
			
			i=j+1;
			j=i;
			
		}
		else {
			if (j<n){
				j++;
			}
			else {
				i++;
				j=i;
			}
		}
	}
	cout<<ans;
	return 0;
}
