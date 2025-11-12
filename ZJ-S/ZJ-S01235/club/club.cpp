#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node{
	int myd,rs;
}s[5];
int n,a[101010],b[101010],c[101010],cishu,mina=INT_MAX,minb=INT_MAX,minc=INT_MAX;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>cishu;
	for(int cishu1=1;cishu1<=cishu;cishu1++){
		cin>>n;
		int sum=n/2;
		int flag=1;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]!=0||c[i]!=0){
				flag=0;
			}
			int maxn=max(max(a[i],b[i]),c[i]);
			if(maxn==a[i]){
				mina=min(mina,maxn);
				if(s[1].rs<n/2){
					s[1].rs++;
					s[1].myd+=maxn;
				}
				else{
					s[1].myd=s[1].myd+maxn-mina;
				}
			}
			else if(maxn==b[i]){
				minb=min(minb,maxn);
				if(s[2].rs<n/2){
					s[2].rs++;
					s[2].myd+=maxn;
				}
				else{
					s[2].myd=s[2].myd+maxn-minb;
				}
			}
			else if(maxn==c[i]){
				minc=min(minc,maxn);
				if(s[3].rs<n/2){
					s[3].rs++;
					s[3].myd+=maxn;
				}
				else{
					s[3].myd=s[3].myd+maxn-minc;
				}
			}
		}
		if(flag){
			sort(b+1,b+n+1);
			int ans=0;
			for(int xy=n;xy>=n/2+1;xy--){
				ans+=b[xy];
			}
			cout<<ans<<endl;
		}
		else{
			cout<<s[1].myd+s[2].myd+s[3].myd<<endl;
		}
	}
	return 0;
}
