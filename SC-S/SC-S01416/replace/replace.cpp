#include<bits/stdc++.h>
using namespace std;
int n,q,ans,t;
string re[3][200005],q1,q2,f;
bool cmp(string e,string g){
	for(int xl=1;xl<=e.size();xl++){
		if(e[xl-1]!=g[xl-1])return false;
	}
	return true;
}
int pd(string a,string b,string c,string d){
	t=0;
	f=c;
	//cout<<f[0]<<b[0];
	if(a.size()>c.size())return 1;
	int m1=a.size(),m2=c.size();
	for(int z=1;z<=m2-m1+1;z++){
		int flag=1;
		//cout<<z;
		for(int x=z;x<=m1+z-1;x++){
			f[x-1]=b[x-z];
			//cout<<f[x-1]<<" ";
			if(a[x-z]!=c[x-1]){
				flag=0;break;
			}
		}
		if(flag==1&&cmp(f,d))t++;
		f=c;
	}
	return t+1;
}
int main(){
	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=2;i++)cin>>re[i][j];	
	}
	for(int vm=1;vm<=q;vm++){
		ans=0;
		cin>>q1>>q2;
		for(int tm=1;tm<=n;tm++){
			ans=pd(re[1][tm],re[2][tm],q1,q2)+ans-1;
		}
		cout<<ans<<"\n";
	}
}