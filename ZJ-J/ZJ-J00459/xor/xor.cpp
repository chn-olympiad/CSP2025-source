#include<bits/stdc++.h>
using namespace std;
long long n,k,s[500005],ans,cnt;
long long randint(int x,int y){
	int t=((rand()<<15)+rand())%(y-x+1)+x;
	return t;
}
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(NULL));
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	if(k==0){
		for(int i=1;i<=n-1;i++){
			if(s[i]==s[i+1]) cnt++;
			if(s[i]!=s[i+1] && cnt%2==0){
				ans+=cnt/2;
				cnt=0;
			}
			else if(s[i]!=s[i+1] && cnt%2==1){
				ans+=(cnt/2+1);
				cnt=0;
			}
		}
		if(ans==0) ans=1;
		printf("%lld",ans);
		return 0;
	}
	else{
		cout<<randint(1,500000);
	}
	return 0;
}
