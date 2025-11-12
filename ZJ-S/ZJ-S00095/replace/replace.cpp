#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int n,q;
string s1[10010],s2[10010];
int len;
string t1,t2,x,y;
int cnt;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s1[i]>>s2[i];
	while(q--) {
		cin>>t1>>t2;
		len=t1.size();
		cnt=0;
		for(int i=0; i<len-1; i++) {
			x=t1.substr(i,len-i);
			y=t2.substr(i,len-i);
			for(int j=(int)x.size()-1; j>=0; j--) {
				for(int k=1; k<=n; k++)
					if(s1[k]==x&&s2[k]==y)
						cnt++;
				if(x[i]!=y[i])
					break;
				x.pop_back();
				y.pop_back();
			}
			if(t1[i]!=t2[i])
				break;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}