#include <bits/stdc++.h>
using namespace std;
long long n,q,i,fn,tl,ll,g,w,t1,h;
string s[200010],c[200010],t,l,x,z;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>s[i]>>c[i];
	while(q--){
		cin>>t>>l;fn=0;
		tl=t.size();ll=l.size();
		for(i=1;i<=n;i++){
			if(s[i].size()>tl||c[i].size()>ll) continue;
			if(t==s[i]&&l==c[i]) fn++;
			g=s[i].size();
			if(g==tl) continue;
			t1=0;w=g-1;
			while(w<=tl){
				h=w+1;
				if(t.substr(t1,w-1)==s[i]&&l.substr(t1,w-1)==c[i])
					if(t.substr(0,t1-1)==l.substr(0,t1-1)&&t.substr(h,tl-1)==l.substr(h,ll-1))
						fn++;
				t1++;w++;
			}
		}
		cout<<fn<<"\n";
	}
	return 0;
}

