#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5e6+5;
int n,q,pos1[MAXN],pos2[MAXN];
string s[MAXN][2],t[MAXN][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	if(n<=100&&q<=100){
		for(int i=1;i<=q;i++){
			int ans=0;
			for(int j=1;j<=n;j++){
				int l=t[i][0].length(),r=s[j][0].length();
				if(l>=r){
					for(int k=0;k<l;k++){
						bool flag=1;
						for(int g=0;g<k;g++){
							flag=(flag&(t[i][0][g]==t[i][1][g]));
						}
						for(int g=k;g<r+k;g++){
							flag=(flag&(t[i][0][g]==s[j][0][g-k]));
							flag=(flag&(t[i][1][g]==s[j][1][g-k]));
						}
						for(int g=r+k;g<l;g++){
							flag=(flag&(t[i][0][g]==t[i][1][g]));
						}
						ans+=(flag);
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i][0].length();j++){
				if(s[i][0][j]=='b') pos1[i]=j;
				if(s[i][1][j]=='b') pos2[i]=j;
			}
		}
		for(int i=1;i<=q;i++){
			ll ans=0,now1=0,now2=0;
			for(int j=0;j<t[i][0].length();j++){
				if(t[i][0][j]=='b') now1=j;
				if(t[i][1][j]=='b') now2=j;
			}
			for(int j=1;j<=n;j++){
				//cout<<now1<<now2<<pos1[j]<<pos2[j]<<"\n";
				if(now1>=pos1[j]&&now1-now2==pos1[j]-pos2[j]&&t[i][0].length()-now1>=s[j][0].length()-pos1[j]){
					ans++;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
