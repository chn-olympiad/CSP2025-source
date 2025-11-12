#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,k,a[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int i=1;
	if(k<=1){
		for(int i=1;i<=n;i++) if(a[i]==k) cnt++;
		cout<<cnt;
		return 0;
	}
	for(;i<=n;){
		int b=a[i];
		if(b==k){
			cnt++;i++;
			continue;
		}
		for(int j=i+1;j<=n;j++){			
			b=b^a[j];
			if(b==k){
				cnt++;
				i=j+1;
				break;
			}
		}
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
