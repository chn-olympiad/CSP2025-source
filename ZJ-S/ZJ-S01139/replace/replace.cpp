#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
string s,t,u,v;
int st,en,siz;
string c[200005][4];
int l[200005],r[200005];
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>a>>b;
    	st=0;en=0;
    	for(int j=0;j<a.size();j++){
    		if(a[j]!=b[j]){
    			st=j;
    			break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]!=b[j]){
				en=j;
				break;
			}
		}
		c[i][0]=a.substr(st,en-st+1);
		c[i][1]=b.substr(st,en-st+1);
		c[i][2]=a.substr(0,st);
		c[i][3]=a.substr(en+1,a.size()-en-1);
		l[i]=st;
		r[i]=a.size()-en-1;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		st=0;en=0;
    	for(int j=0;j<a.size();j++){
    		if(a[j]!=b[j]){
    			st=j;
    			break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]!=b[j]){
				en=j;
				break;
			}
		}
		s=a.substr(st,en-st+1);
		t=b.substr(st,en-st+1);
		siz=a.size();
		for(int j=1;j<=n;j++){
			if(st>=l[j] && siz-1-en>=r[j]){
			    u=a.substr(st-l[j],l[j]);
		        v=a.substr(en+1,r[j]);
			    if(s==c[j][0] && t==c[j][1] && u==c[j][2] && v==c[j][3]){
				    ans++;
			    }
		    }
		}
		cout<<ans<<endl;
	}
	return 0;
} 
