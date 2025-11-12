#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
string a[N],b[N];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		string s,t;
		cin>>s>>t;
		int ans=0;
		for(int i=1;i<=n;i++){
			int j=s.find(a[i]);
//			cout<<a[i]<<' ';
			while(j!=-1&&j<s.size()){
//				cout<<j<<'\n';
//				cout<<a[i]<<'\n';
//				cout<<j<<'\n';
				string tmp=s;
				for(int k=0;k<b[i].size();k++){
					tmp[k+j]=b[i][k];
				}
//				cout<<tmp<<'\n';
				if(tmp==t)ans++;
//				j=j+k;
				j=s.find(j+1);
			}
		}
		cout<<ans<<'\n';
//		cout<<'\n'<<'\n';
	} 
	
	return 0;
}

























