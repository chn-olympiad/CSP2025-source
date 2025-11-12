#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct Node{
	string s1,s2;
}a[N],b[N];
int n,q,ans;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=n;i++){
		int m=a[i].s1.size();
		int l=0,r=m-1;
		for(int j=0;j<m;j++){
			if(a[i].s1[j]==a[i].s2[j])
			l++;
			else break;
		}
		for(int j=m-1;j>=0;j--){
			if(a[i].s1[j]==a[i].s2[j])
			r--;
			else break;
		}
		string x,y;
		for(int j=l;j<=r;j++){
			x+=a[i].s1[j];
			y+=a[i].s2[j];
		}
		a[i].s1=x;
		a[i].s2=y;
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].s1>>b[i].s2;
	}
	for(int i=1;i<=q;i++){
		int m=b[i].s1.size();
		int l=0,r=m-1;
		for(int j=0;j<m;j++){
			if(b[i].s1[j]==b[i].s2[j])
			l++;
			else break;
		}
		for(int j=m-1;j>=0;j--){
			if(b[i].s1[j]==b[i].s2[j])
			r--;
			else break;
		}
		string x,y;
		for(int j=l;j<=r;j++){
			x+=b[i].s1[j];
			y+=b[i].s2[j];
		}
		b[i].s1=x;
		b[i].s2=y;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			if(b[i].s1==a[j].s1&&b[i].s2==a[j].s2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

