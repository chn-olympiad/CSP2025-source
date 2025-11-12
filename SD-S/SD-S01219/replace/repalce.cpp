#include<bits/stdc++.h>
using namespace std;
long long n,q,ss1[200005],ss2[200005],ans;
string t1,t2,s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		ss1[i]=s1.size();
		ss2[i]=s2.size();
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		if(t1.size()>t2.size()){
			for(int i=1;i<=n;i++){
				if(ss1[i]>ss2[i]){
					ans++;
				}
			}
			printf("%lld\n",ans);
		}
		if(t1.size()<t2.size()){
			for(int i=1;i<=n;i++){
				if(ss1[i]<ss2[i]){
					ans++;
				}
			}
			printf("%lld\n",ans);
		}
		if(t1.size()==t2.size()){
			for(int i=1;i<=n;i++){
				if(ss1[i]==ss2[i]){
					ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
