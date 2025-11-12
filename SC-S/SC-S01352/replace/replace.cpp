#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
int ans;
struct qaq{
	string x,y;
}a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
	}
	while(q--) {
		string s1,s2;
		ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++) {
			if(a[i].x.length()<s1.length()){
				if((s1.find('b')-a[i].x.find('b')+a[i].y.find('b'))==s2.find('b')) {
					if((s1.length()-s1.find('b'))>=(a[i].x.length()-a[i].x.find('b'))) {
						if(s1.find('b')>=a[i].x.find('b')) ans++;
					}
				}
			} else {
				if(a[i].x.length()==s1.length()&&a[i].x==s1) {
					if(a[i].y==s2) ans++;
				}
			}
		}
		cout<<ans<<"\n";
		
	}
	
	return 0; 
}