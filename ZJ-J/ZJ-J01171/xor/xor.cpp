#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;

long long pre[N];

struct st{
	long long s,t;
};

int main(){
//	freopen("xor.in","r",stdin);ccfccf
//	freopen("xor.out","w",stdout);ccfccf
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	scanf("%d %lld",&n,&k);
	long long x;
	int ans=0;
	int last=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);	
		pre[i]=pre[i-1]^x;
		for(int j=i;j>last;j--){
			if((pre[i]^pre[j-1])==k){
				last=i;
				ans++;
				break; 
			}                      
		}
	}
	printf("%d",ans);
	return 0;
}
/*
这TM怎么异或优先级还没==高，调了我至少10min
感觉预期324，可能会高一点 
ccf is really good,so please to give me 1=.
I love ccf!!!!!!!!!!!!
*/
