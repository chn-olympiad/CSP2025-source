#include<bits/stdc++.h>
using namespace std;
long long n,q;
string sa[200010],sb[200010],ta,tb,taa,tbb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++)
		cin>>sa[i]>>sb[i];
	for(long long i=1;i<=q;i++){
		long long cnt=0;
		cin>>ta>>tb;
		for(long long j=1;j<=n;j++){
			taa=ta,tbb=tb;
			long long finda=taa.find(sa[j]),findb=tbb.find(sb[j]);
			if(!(finda^-1)||!(findb^-1))
				continue;
			if(finda^findb)
				continue;
			taa.erase(finda,sa[j].size());
			tbb.erase(findb,sb[j].size());
			bool flag=true;
			for(long long j=0;j<taa.size();j++)
				if(taa[j]^tbb[j]){
					flag=false;
					break;
				}
			if(flag)
				cnt++;
		}
		printf("%lld\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
