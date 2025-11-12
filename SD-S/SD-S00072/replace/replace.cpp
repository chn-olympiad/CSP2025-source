#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e6+9;
int n,q,n1;
int sz[N];
//unsigned ll a[N],b[N],fac[N];
string s1[N],s2[N];
//unsigned ll h1[N],h2[N];
//inline unsigned ll num1(int l,int r){
//	return (h1[l]-h1[r+1])/fac[n1-r+1];
//}
//inline unsigned ll num2(int l,int r){
//	return (h2[l]-h2[r+1])/fac[n1-r+1];
//}
//unsigned ll ha[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
//	fac[0]=1;
//	for(int i=1;i<=1e6;i++){
//		fac[i]=fac[i-1]*1331;
//	}
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sz[i]=s1[i].size();
//		s=" "+s;
//		for(int j=1;j<=sz[i];j++){
//			ha[j]=ha[j-1]*1331+s[j]*7;
//		}
//		a[i]=(ha[1]-ha[sz[i]+1])/fac[1];
//		
//		cin>>s;
//		for(int j=1;j<=sz[i];j++){
//			ha[j]=ha[j-1]*1331+s[j]*7;
//		}
//		b[i]=(ha[1]-ha[sz[i]+1])/fac[1];
//		cout<<a[i]<<" "<<b[i]<<"\n";
	}
	string t1,t2;
	while(q--){
		cin>>t1>>t2;
		n1=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j+sz[i]-1<=n1;j++){
				if(t1.substr(j,sz[i])==s1[i]){
					if(t2.substr(j,sz[i])==s2[i]){
						if(t1.substr(1,j-1)==t2.substr(1,j-1)&&t1.substr(j+sz[i])==t2.substr(j+sz[i])) ans++;
					}
				}
			}
		}
//		for(int i=1;i<=n1;i++){
//			h1[i]=h1[i-1]*1331+t1[i]*7;
//		}
//		for(int i=1;i<=n1;i++){
//			h2[i]=h2[i-1]*1331+t2[i]*7;
//		}
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j+sz[i]<=n1;j++){
//				cout<<j<<" "<<j+sz[i]<<" "<<num1(j,j+sz[i])<<" "<<num2(j,j+sz[i])<<"\n";
//				if(num1(j,j+sz[i])==a[i]){
//					if(num2(j,j+sz[i])==b[i]){
//						ans++;
//					}
//				}
//			}
//		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

