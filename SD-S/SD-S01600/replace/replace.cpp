#include<bits/stdc++.h>
#define int long long
using namespace std;
const int k=971,m=71111111;
//const int k=100,m=999998244353;
int n,q,a[200005],b[200005],l[200005],qt[200005],qtt[200005];
string s,ss,t,tt;
int ksm(int a,int b){
	int s=1;
	while(b){
		if(b&1)s=s*a%m;
		a=a*a%m,b>>=1;
	}
	return s%m;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>ss;
		l[i]=s.size();
		for(int j=0;j<l[i];j++)a[i]=(a[i]*k%m+s[j]-96)%m;
		for(int j=0;j<l[i];j++)b[i]=(b[i]*k%m+ss[j]-96)%m;
//		cerr<<a[i]<<" "<<b[i]<<"\n";
	}
	while(q--){
		cin>>t>>tt;
		if(t.size()!=tt.size()){
			cout<<"0\n";
			continue;
		}
		int ll=t.size(),c=0;
		qt[0]=(t[0]-96)%m;
		for(int i=1;i<ll;i++)qt[i]=(qt[i-1]*k%m+t[i]-96)%m;
		qtt[0]=(tt[0]-96)%m;
		for(int i=1;i<ll;i++)qtt[i]=(qtt[i-1]*k%m+tt[i]-96)%m;
		int x=-1,y=-1;
//		for(int i=0;i<ll;i++)cerr<<qt[i]<<"\n";
//		for(int i=0;i<ll;i++)cerr<<qtt[i]<<"\n";
		for(int i=0;i<ll;i++){
			if(t[i]!=tt[i]){
				x=i;
				break;
			}
		}
		for(int i=ll-1;i>=0;i--){
			if(t[i]!=tt[i]){
				y=i;
				break;
			}
		}
		for(int i=0;i<=n;i++){
			if(l[i]<y-x+1)continue;
			for(int j=x;j>=0;j--){//max(x-(l[i]-(y-x+1)),0)
				if(j+l[i]>ll)continue;
				if(j+l[i]<=y)break;
				if(j==0){
					if(qt[j+l[i]-1]==-1)continue;
					int T=(qt[j+l[i]-1]+m)%m;
					int TT=(qtt[j+l[i]-1]+m)%m;
					if(a[i]==T&&b[i]==TT)c++;//cerr<<"C"<<i<<"\n";
					continue;
				}
				if(qt[j+l[i]-1]==-1)continue;
				if(qt[j-1]==-1)continue;
				int T=(qt[j+l[i]-1]-qt[j-1]*ksm(k,l[i])%m+m)%m;
				int TT=(qtt[j+l[i]-1]-qtt[j-1]*ksm(k,l[i])%m+m)%m;
				if(a[i]==T&&b[i]==TT)c++;//cerr<<"C"<<i<<"\n";
			}
		}
//		for(int i=0;i<=n;i++){
//			for(int j=0;j<=ll;j++){
//				if(j==0){
//					int T=(qt[j+l[i]-1]+m)%m;
//					int TT=(qtt[j+l[i]-1]+m)%m;
//					if(a[i]==T&&b[i]==TT)c++;
//					continue;
//				}
//				int T=(qt[j+l[i]-1]-qt[j-1]*ksm(k,l[i])%m+m)%m;
//				int TT=(qtt[j+l[i]-1]-qtt[j-1]*ksm(k,l[i])%m+m)%m;
//				if(a[i]==T&&b[i]==TT)c++;
//			}
//		}
		cout<<c<<"\n";
//		cerr<<c<<"\n";
		for(int i=0;i<=ll;i++)qt[i]=-1,qtt[i]=-1;
	}
	return 0;
} 
