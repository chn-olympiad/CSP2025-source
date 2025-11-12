#include<bits/stdc++.h>
using namespace std;
const int N=5e5+11,M=(1<<21)+1;
int n,k,a[N],sum[N],ans,last;
stack<int>st;
bool inst[M];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	inst[0]=true;
	st.push(0);
	for(int i=1;i<=n;i++){
		if(inst[sum[i]^sum[last]^k]){
			while(!st.empty()){
				int t=st.top();
				inst[t]=false;
				st.pop();
			}
			last=i;
			ans++;
		}
		st.push(sum[i]^sum[last]);
		inst[sum[i]^sum[last]]=true;
	}
	printf("%d\n",ans);
	return 0;
}