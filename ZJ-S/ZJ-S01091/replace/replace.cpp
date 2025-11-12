#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q;
ll ans;
string s1,s2;
int a[N][5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int l=s1.size();
		a[i][3]=l;
		for(int j=1;j<=l;j++){
			if(s1[j-1]=='b') a[i][0]=j;
			if(s2[j-1]=='b') a[i][1]=j;
		}
	}
	while(q--){
		ans=0;
		cin>>s1>>s2;
		int l=s1.size();
		int pos1,pos2;
		for(int j=1;j<=l;j++){
			if(s1[j-1]=='b') pos1=j;
			if(s2[j-1]=='b') pos2=j;
		}
		for(int i=1;i<=n;i++){
			if(a[i][3]!=l) continue;
			if(a[i][0]!=pos1) continue;
			if(a[i][0]!=pos2&&a[i][1]!=pos2) continue;
			if(a[i][0]==pos2) ans+=min(a[i][0],a[i][1])*(l-max(a[i][0],a[i][1])+1);
			if(a[i][1]==pos2) ans+=min(a[i][0],a[i][1])*(l-max(a[i][0],a[i][1])+1);
		}
		cout<<ans;
	}
	return 0;
}
