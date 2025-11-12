#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
string a,b;
struct inf{
	int y,w;
}s1[200005],s2[200005],st1,st2;
int main () {
	freopen("replace.in", "r",stdin);
	freopen("replace.out", "w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=0;j<a.size();j++){
			if(a[j]=='b'){
				s1[i].w=j;
				s1[i].y=a.size()-j-1;
				break;
			}
		}
		for(int j=0;j<b.size();j++){
			if(b[j]=='b'){
				s2[i].w=j;
				s2[i].y=b.size()-j-1;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		ans=0;
		for(int j=0;j<a.size();j++){
			if(a[j]=='b'){
				st1.w=j;
				st1.y=a.size()-j-1;
				break;
			}
		}
		for(int j=0;j<b.size();j++){
			if(b[j]=='b'){
				st2.w=j;
				st2.y=b.size()-j-1;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(s1[j].w-s2[j].w==st1.w-st2.w&&s1[j].w<=st1.w&&s1[j].y<=st1.y) ans++;
		}
		cout<<ans<<endl;
	}
    return 0;
}

