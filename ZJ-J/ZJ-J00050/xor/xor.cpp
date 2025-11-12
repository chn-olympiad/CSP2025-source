#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;

int n,k,a[maxn],sum[maxn],ans;
set<int> st;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	st.insert(0);
	for (int i=1;i<=n;i++){
		int tmp=sum[i]^k;
		if (st.find(tmp)!=st.end()){
			ans++;
			st.clear();
		}
		st.insert(sum[i]);
	}
	printf("%d",ans);
	return 0;
}
