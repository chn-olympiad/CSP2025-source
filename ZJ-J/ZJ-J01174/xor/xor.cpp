#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans=0;
int a[N];
int x[201],y[201],z[201];
string sze(int m){
	string s="";
	while(m){
		s=s+char(m%2+'0');
		m/=2;
	}
	if(s!="")return s;
	else return "0";
}
int x_a(int g,int h){
	memset(x,0,sizeof x);
	memset(y,0,sizeof y);
	memset(z,0,sizeof z);
	string sx=sze(g);
	string sy=sze(h);
	int lenx=sx.size();
	int leny=sy.size();
	int len=max(lenx,leny);
	for(int i=0;i<lenx;i++) x[i]=sx[lenx-i-1]-'0';
	for(int i=0;i<leny;i++) y[i]=sy[leny-i-1]-'0';
	for(int i=0;i<len;i++){
		if(x[i]==y[i]) z[i]=0;
		else z[i]=1;
	}
	int sum=0,cheng=1;
	for(int i=len-1;i>=0;i--){
		sum=sum+z[i]*cheng;
		cheng*=2;
	}
	return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int i=1;
	while(i<=n){
		int b=a[i];
		if(b==k) ans++;
		for(int j=i+1;j<=n;j++){
			b=x_a(b,a[j]);
			if(b==k){
				i=j-1;
				ans++;
				break;
			}
		}i++;
	}
	cout<<ans;
	return 0;
}

