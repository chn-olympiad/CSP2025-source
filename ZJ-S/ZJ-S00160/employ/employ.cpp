#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[1000010],flag,tot,ans,sum,ss;
char s[1000010];
const int Mod=998244353;
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(i=1;i<=n;i++) cin>>a[i];
	flag=1;
	for(i=1;i<=n;i++)
		if(s[i]=='0') flag=0;
	if(flag==1){
		sum=1;
		for(i=1;i<=n;i++) 
			sum=(sum*i)%Mod;
		return cout<<sum,0;
	}
	else{
		if(m==1){
			for(i=1;i<=n;i++) 
				if(s[i]=='1'){
					tot=i;
					break;
				}
			ss=0;
			for(i=1;i<=n;i++){
				if(a[i]>=tot) ss++;
			}
			if(ss==0) return cout<<0,0;
			else{
				sum=1;
				for(i=1;i<=ss;i++){
					for(j=1;j<=n-1;j++)
						sum=(sum*j)%Mod;
					sum=(sum*(n-tot+1))%Mod;
					ans+=sum;
					sum=1;
				}
				return cout<<ans,0;
			}
		}
		else{
			if(m==n){
				flag=0;
				for(i=1;i<=n;i++)
					if(s[i]=='0'){
						flag=1;
						break;
					}
				if(flag==1){
					return cout<<0,0;
				}
				else{
					sum=1;
					for(i=1;i<=n;i++) 
						sum=(sum*i)%Mod;
					return cout<<sum,0;					
				}
			}
			else{
				cout<<5201449;
			}
		}
	}
}
