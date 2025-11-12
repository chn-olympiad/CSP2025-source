#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[n+1][3];
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}string t,tt;
	for(int i=1;i<=q;i++){
		cin>>t>>tt;
		int ans=0;
		for(int j=1;j<=n;j++){
			int a,b,c,d,e,f,g,h;
			a=t.find('b');
			b=t.size()-a-1;
			c=s[i][1].find('b');
			d=s[i][1].size()-c-1;
			e=tt.find('b');
			f=tt.size()-e-1;
			g=s[i][2].find('b');
			h=s[i][2].size()-g-1;
			if(a>=c&&b>=d&&e>=g&&f>=h){
				int qian=a-c;
				int hou=t.size()-qian-s[i][1].size();
				if(t.substr(0,qian)+s[i][2]+t.substr(t.size()-hou,hou)==tt){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
