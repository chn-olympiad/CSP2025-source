#include<bits/stdc++.h>
using namespace std;
int t;
int n,a1[200000],a2[200000],a3[200000];
int m[200000],s1[200000],s2[200000];
int dp[100000][5][3];
int limn[5];
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		cin>>n;
		int sa1=0,sa2=0,sa3=0;
		int na1=0,na2=0,na3=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>a2[i] && a1[i]>a3[i]){
				m[i]=1;
				if(a2[i]>=a3[i]){
					s1[i]=2;
					s2[i]=3;
				}
				if(a2[i]<a3[i]){
					s1[i]=3;
					s2[i]=2;
				}
				sa1+=a1[i];na1++;
			}
			else if(a2[i]>a1[i] && a2[i]>a3[i]){
				m[i]=2;
				if(a1[i]>=a3[i]){
					s1[i]=1;
					s2[i]=3;
				}
				if(a1[i]<a3[i]){
					s1[i]=3;
					s2[i]=1;
				}
				sa2+=a2[i];na2++;
			}
			else if(a3[i]>a1[i] && a3[i]>a2[i]){
				m[i]=3;
				if(a2[i]>=a1[i]){
					s1[i]=2;
					s2[i]=1;
				}
				if(a2[i]<a1[i]){
					s1[i]=1;
					s2[i]=2;
				}
				sa3+=a3[i];na3++;
			}
			//cout<<sa1<<" "<<sa2<<" "<<sa3<<endl;
		}
		int lim=n/2;
		if(na1<=lim && na2<=lim && na3<=lim){
			cout<<sa1+sa2+sa3<<endl;
			continue;
		}
		else{
			sort(a1+1,a1+n+1);
			ans=0;
			for(int i=n;i>=1;i++){
				ans+=a1[i];
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
} 
