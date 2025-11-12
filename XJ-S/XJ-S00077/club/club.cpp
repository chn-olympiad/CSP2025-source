#include<bits/stdc++.h>
using namespace std;
struct P{
	int a,b,c,t;
}s[100005];
bool cmp(P x,P y){
	return x.t>y.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		vector<int> dp(n+1),k(n+1);
		int xxx=0,yyy=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].t=max(s[i].a,max(s[i].b,s[i].c));
			xxx=max(xxx,s[i].b);
			yyy=max(yyy,s[i].c);
		}
		sort(s+1,s+n+1,cmp);
		int cntA=0,cntB=0,cntC=0;
		if(yyy==0){
			int ans=0;
			if(xxx==0){
				for(int i=1;i<=n/2;i++){
					ans+=s[i].a;
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(cntA<n/2&&cntB<n/2){
						if(s[i].a>s[i].b){
							ans+=s[i].a;
							cntA++;
						}
						else{
							ans+=s[i].b;
							cntB++;
						}
					}
					else if(cntA<n/2){
						ans+=s[i].a;
						cntA++;
					}
					else{
						ans+=s[i].b;
						cntB++;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		dp[1]=s[1].t;
		for(int i=1;i<=n;i++){
			bool flagA=false,flagB=false,flagC=false;
			if(s[i].t==s[i].a){
			    cntA++;k[i]=1;
			    flagA=true;
			}
			else if(s[i].t==s[i].b){
			    cntB++;k[i]=2;
			    flagB=true;
			}
			else{
			    cntC++;k[i]=3;
			    flagC=true;
			}
			if(flagA){
				if(cntA<=n/2){
					dp[i]=dp[i-1]+s[i].a;
				}
				else{
					cntA--;
					if(s[i].b>=s[i].c){
						dp[i]=dp[i],dp[i-1]+s[i].b;
						cntB++;k[i]=2;
					}
					else{
						dp[i]=dp[i],dp[i-1]+s[i].c;
						cntC++;k[i]=3;
					}
					if(i>1){
					    int j=i-1;
					    while(k[j]!=1){
						    j--;
					    }
					    int sum=dp[i-1]-s[j].a+max(s[j].b,s[j].c)+s[i].a;
					    dp[i]=max(dp[i],sum);
				    }
				}
			}
			if(flagB){
				if(cntB<=n/2){
					dp[i]=dp[i-1]+s[i].b;
				}
				else{
					cntB--;
					if(s[i].a>=s[i].c){
						dp[i]=dp[i-1]+s[i].a;
						cntA++;k[i]=1;
					}
					else{
						dp[i]=dp[i-1]+s[i].c;
						cntC++;k[i]=3;
					}
					if(i>1){
					    int j=i-1;
					    while(k[j]!=2){
						    j--;
					    }
					    int sum=dp[i-1]-s[j].b+max(s[j].a,s[j].c)+s[i].b;
					    dp[i]=max(dp[i],sum);
				    }
				}
			}
			if(flagC){
				if(cntC<=n/2){
					dp[i]=dp[i-1]+s[i].c;
				}
				else{
					cntC--;
					if(s[i].b>=s[i].a){
						dp[i]=dp[i-1]+s[i].b;
						cntB++;k[i]=2;
					}
					else{
						dp[i]=dp[i-1]+s[i].a;
						cntA++;k[i]=1;
					}
					if(i>1){
					    int j=i-1;
					    while(k[j]!=3){
						    j--;
					    }
					    int sum=dp[i-1]-s[j].c+max(s[j].a,s[j].b)+s[i].c;
					    dp[i]=max(dp[i],sum);
				    }
				}
			}
		}
		cout<<dp[n]<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
