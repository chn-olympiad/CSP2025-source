//SN-S00649 袁浩文 西安辅轮中学
#include <bits/stdc++.h> 
#define int long long
using namespace std;
int n,q,ans;
string s[200005][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		ans=0;
		int cnt;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<a.size();i++){
			for(int j=1;j<=n;j++){
				int flag=1;
				if(s[j][1][0]==a[i]){
//					cout<<"same:"<<s[j][1]<<" ";
					for(int k=i;k<=i+s[j][1].size()-1;k++){
//						cout<<"compare:"<<s[j][1][k-i]<<" "<<a[k]<<"\n";
						if(s[j][1][k-i]!=a[k]){
							flag=0;
						}
					}
//					cout<<"debug:"<<a<<"\n";
					if(flag==1){
						string cc=a;
						for(int k=i;k<=i+s[j][1].size()-1;k++){
							cc[k]=s[j][2][k-i];
						}
//						cout<<"de:"<<cc<<"\n";
						if(cc==b)ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}
