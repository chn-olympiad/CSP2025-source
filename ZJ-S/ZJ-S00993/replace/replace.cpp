#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define OpenFile(_) freopen(#_ ".in","r",stdin);freopen(#_ ".out","w",stdout)
typedef long long Int;

Int n,q;
string a[200005],b[200005],x,y,z;

int main(){
	IOS;OpenFile(replace);

	cin>>n>>q;
	for(Int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(Int i=1;i<=q;i++){
		Int ans=0;
		cin>>x>>y;
		for(Int j=1;j<=n;j++){
			z=x;
			Int pos=z.find(a[j]);
			if(pos!=-1&&z.replace(pos,b[j].length(),b[j])==y)++ans;
		}
		cout<<ans<<endl;
	}

	return 0;
}

