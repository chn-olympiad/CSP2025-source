#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ll[N],cnt;
string s[N],t[N],a,b,c;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		ll[i]=s[i].size();
		s[i]=" "+s[i];
		t[i]=" "+t[i];
	}
	for(int cat=1;cat<=q;cat++){
		int ans=0,f=0,e=0;
		cin>>a>>b;
		int l=a.size(),l2=b.size();
		a=" "+a;
		b=" "+b;
		c=a;
		if(l!=l2){
			cout<<0<<"\n";
			continue ;
		}
		for(int i=1;i<=l;i++)
			if(!f&&a[i]!=b[i])f=i,e=i;
			else if(a[i]!=b[i])e=i;
		for(int i=1;i<=n;i++){
			if(ll[i]<e-f+1)continue ;
			for(int j=1;j<=l;j++){
				if(f<j)break ;
				if(j+ll[i]-1>l||j+ll[i]-1<e)continue ;
				bool p=1;
				for(int k=1;k<=ll[i];k++)
					if(a[j+k-1]!=s[i][k]){
						p=0;
						break ;
					}
					else if(t[i][k]!=b[j+k-1]){
						p=0;
						break ;
					}
				if(p)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb