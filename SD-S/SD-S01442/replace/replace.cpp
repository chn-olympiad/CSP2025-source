#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ss1[200010],ss2[200010],ans;
string s1[200010],s2[200010],q1,q2;
int p1=131,p2=1000000000091;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int l=s1[i].size();
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		ss1[i]=ss2[i]=1;
		for(int j=1;j<=l;j++){
			ss1[i]=ss1[i]*p1+s1[i][j];
			ss1[i]%=p2;
		}
		for(int j=1;j<=l;j++){
			ss2[i]=ss2[i]*p1+s2[i][j];
			ss2[i]%=p2;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;
		int l=q1.size();
		q1=" "+q1+" ";
		q2=" "+q2+" ";
		for(int j=0;j<l;j++){
			if(q1[j]!=q2[j])break;
			for(int k=l+1;k>j+1;k--){
				if(q1[k]!=q2[k])break;
				int su1=1,su2=1;
				for(int m=j+1;m<=k-1;m++){
					su1=su1*p1+q1[m];
					su2=su2*p1+q2[m];
					su1%=p2;
					su2%=p2;
				}
				for(int m=1;m<=n;m++){
					if(su1==ss1[m]&&su2==ss2[m]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	
	return 0;
}
