#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,op,F=1;
map<int,int>mp[2];
#define PII pair<int,int>
#define fir first
#define sec second
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]>1)F=0;
	}
	if(F){
		if(k==1){
			for(int i=1;i<=n;++i)
				if(a[i]==1)++ans;
		}
		else{
			for(int i=1;i<=n;++i){
				if(a[i]==0)++ans;
				else if(a[i+1]==1)++ans,++i;
			}
		}
		cout<<ans;
	}
	else {
	for(int i=1;i<=n;++i){
		op=1-op;
		if(a[i]==k){
			++ans;
			mp[0].clear();
			mp[1].clear();	
			continue;
		}
		bool flag=1;
		for(const PII&s:mp[1-op]){
			int now=s.fir^a[i];
			mp[op][now]=s.sec;
			if(now==k){
				++ans;
				//printf("i:%d a:%d s:%d pos:%d\n",i,a[i],s.fir,s.sec);
				flag=0;
				break;
			}
		}
		if(flag)mp[op][a[i]]=i;
		else{
			mp[0].clear();
			mp[1].clear();	
		}
	}
	printf("%d",ans);
	}
	return 0;
}
