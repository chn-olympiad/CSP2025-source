#include <bits/stdc++.h>
using namespace std;
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fr2(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define baka; cout<<j<<" "<<j+i-1<<" "<<used[j][j+i-1]<<" "<<m[j][j+i-1]<<endl;
const int maxn=5e5+10;
int n,ans=0;
string s[maxn],k;
map<int,string> m[maxn];
map<int,bool> used[maxn];
inline string to2(int p) {
	string p1="";
	while(p>0) {
		p1=char((p%2)+'0')+p1;
		p/=2;
	}
	fr1(i,p1.length(),20)p1='0'+p1;
	return p1;
}
inline void read() {
	int p;
	cin>>n>>p;
	k=to2(p);
	fr1(i,1,n) {
		cin>>p;
		s[i]=to2(p);
	}
	return ;
}
inline string xr(string a,string b) {
	string p="";
	fr1(i,0,20)p+=(a[i]==b[i]?'0':'1');
	return p;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	read();
	fr1(i,1,n)fr1(j,1,n-i+1) {
		if(i==1) {
			m[j][j]=s[j];
			if(s[j]==k) {
				ans++,used[j][j]=1;
			}
//			baka;
		} else {
			if(used[j][j+i-2]||used[j+i-1][j+i-1]){
				used[j][j+i-1]=1;
//				baka;
				continue;
			}
			m[j][j+i-1]=xr(m[j][j+i-2],m[j+i-1][j+i-1]);
			if(m[j][j+i-1]==k) {
				used[j][j+i-1]=1,used[j][j]=1,ans++;
//				baka;
				break;
			}
//			baka;
		}
	}
	cout<<ans<<endl;
	return 0;
}
