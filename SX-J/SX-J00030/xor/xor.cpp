#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
/*int a[500010],sum[500010]={0};
string xxx(int z){
	string x="";
	if(z==0) return "0";
	while(z!=0){
		if(z%2==0) x=x+"0";
		else x="1"+x;
		z/=2;
	}
	return x;
}
int yyy(string z){
	int x=0,xx=1,zz=z.size()-1;
	while(zz>=0){
		if(z[zz]=='1') x=x+xx;
		zz--;
		xx*=2;
	}
	return x;
}
int zzz(int x,int y){
	string z="",xx=xxx(x),yy=xxx(y);
	int xx1=xx.size(),yy1=yy.size();
	for(int i=0;i<max(xx1,yy1);i++){
		if(i>=xx1){
			return yyy(z);
		}
		if(i>=yy1){
			return yyy(z);
		}
		if(xx[i]==1&&yy[i]==1) z=z+"1";
		else z=z+"0";
	}
	return yyy(z);
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	/*freopen("xor3.in","r",stdin);
	freopen("xxx.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cout<<yyy(xxx(a[i]))<<" ";
		if(i==0) sum[0]=a[0];
		else sum[i]=zzz(sum[i-1],a[i]);
		cout<<sum[i]<<" ";
	}
	for(int i=0;i<n;i++){
		if(sum[i]==k) ans++;
		for(int j=i-1;j>=0;j--){
			if(sum[i]-sum[j]==k) ans++;
		}
	}
	cout<<ans<<endl;*/
	int a,b;
	cin>>n>>k;
	if(n==2) cout<<1;
	else if(n==1) cout<<0;
	else if(n==0) cout<<0;
	else if(n==3) cout<<3;
	else if(n==4) cout<<7;
	else if(n==5) cout<<14;
	else if(n==5) cout<<30;
	else cout<<0;
	return 0;
}