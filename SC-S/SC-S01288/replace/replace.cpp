#include<bits/stdc++.h>
#define int long long
#define I ios_base::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
#define endl '\n'
using namespace std;
const int maxn=5000100;
string strn1[maxn],strn2[maxn];
int n,q; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	I AK CSP 
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>strn1[i]>>strn2[i];
	for(int i=1;i<=q;i++){
		int ans=0;
		string qus1,qus2; 
		cin>>qus1>>qus2; 
		qus1=" "+qus1+" "; 
		qus2=" "+qus2+" ";
		for(int l=0,r=qus1.size()-1;l<=r;l++){
			if(qus1.substr(0,l+1)==qus2.substr(0,l+1) && qus1.substr(r,qus1.size()-r)==qus2.substr(r,qus2.size()-r))
			{
				for(int j=1;j<=n;j++)if(strn1[j]==qus1.substr(l+1,r-l-1) && strn2[j]==qus2.substr(l+1,r-l-1))ans++;
			} 
			else {l=0; r--;}
		}
		cout<<ans<<endl;
	}
	return 0;
}