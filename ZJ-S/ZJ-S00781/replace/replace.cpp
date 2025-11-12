#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
string s1[N],s2[N];
int n,q,ans;
int check(string s1,string s2,string x,string y){
	if(s1.size()>x.size()) return 0;
	int cnt=0;
	int a=s1.size();
	int b=x.size();
	int i=0;
	while(i<b){
		int j=0,l=i;
		while(s1[j]==x[l]&&l<b&&j<a)
			j++,l++;
		if(j==a){
			string p=x;
			int h=0;
			for(int k=i;k<=i+a-1;k++) p[k]=s2[h++];
			if(p==y){
				cnt++;
			}
		}
		i++;
	}
	return cnt;
}
void solve(){
	string x,y;
	cin>>x>>y;
	ans=0;
	for(int i=1;i<=n;i++)
		ans+=check(s1[i],s2[i],x,y);
	cout<<ans<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
		solve();
	return 0;
}