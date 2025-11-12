#include<bits/stdc++.h>
using namespace std;
int n,k;
string s1[200005],s2[200005],q1,q2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=k;i++){
		cin>>q1>>q2;
		int ans=0;
		for(int p=1;p<=n;p++){
//			cout<<"P:"<<p<<endl;
			if(s1[p].size()>q1.size()) continue;
			for(int j=0;j<=q1.size()-s1[p].size();j++){
				string t=q1;bool f=0;
//				cout<<j<<endl;
				for(int l=j;l<j+s1[p].size();l++){
//					cout<<l<<' '<<l-j<<' '<<q1[l]<<' '<<s1[p][l-j]<<endl;
					if(q1[l]!=s1[p][l-j]) {
						f=1;
						break;
					}
				}
				if(f==1) continue;
				for(int l=j;l<j+s2[p].size();l++){
					t[l]=s2[p][l-j];
				}
//				cout<<t<<endl;
				if(t==q2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
