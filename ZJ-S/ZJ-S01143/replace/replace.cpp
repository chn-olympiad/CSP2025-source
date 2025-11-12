#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,q,ans;

struct node{
	string a,b;
}fs[N],s[N];
node f(node x){
	string sa=x.a,sb=x.b,sc="",sd="";
	node y;
	int len=sa.size(),l=0,r=len-1;
	while(l+1<len&&sa[l]==sb[l])l++;
	while(r>0&&sa[r]==sb[r])r--;
	for(int i=l;i<=r;i++){
		sc+=sa[i];
		sd+=sb[i];
	}
	y.a=sc,y.b=sd;
	return y;
}
int f2(node x){
	string sa=x.a,sb=x.b;
	int len=sa.size(),l=0;
	while(l+1<len&&sa[l]==sb[l])l++;
	return l;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;	
		fs[i]=f(s[i]);
	}
	while(q--){
		node t,ft;
		
		cin>>t.a>>t.b;
		ans=0;
		
		ft=f(t);
		for(int i=1;i<=n;i++){
//			cout<<i<<" "<<fs[i].a<<" "<<fs[i].b<<endl; 
			if(ft.a==fs[i].a&&ft.b==fs[i].b){
				int delta=f2(t)-f2(s[i]),b=1;
				int len=s[i].a.size();
//				cout<<"del:"<<delta<<endl;
				if(s[i].a.size()>t.a.size())continue;
				for(int j=0;j<len;j++){
					if(t.a[j+delta]!=s[i].a[j]||t.b[j+delta]!=s[i].b[j]){
						b=0;
						break;
					}
				}
				if(b)ans++;
				
			}
		}
		
		cout<<ans<<endl;
	}
		
	return 0;
}


