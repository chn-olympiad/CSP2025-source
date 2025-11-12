#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500005];
string ten_two(int x){
	string ans="";
	while(x>=1){
		int a=x%2;
		x/=2;
		ans+=a+'0';
	}
	for(int i=0,j=ans.size()-1;i<j;i++,j--){
		char xc=ans[i];
		ans[i]=ans[j];
		ans[j]=xc;
	}
	return ans;
}
int two_ten(string x){
	int xsi=x.size();
	int ans=0;
	for(int i=xsi-1,j=0;i>=0;i--,j++){
		ans+=(x[i]-'0')*pow(2,j);
	}
	return ans;
}
int yi(int x,int y){
	string xs=ten_two(x),ys=ten_two(y),anss="";
	int xssi=xs.size(),yssi=ys.size();
	for(int i=0,j=xs.size()-1;i<j;i++,j--){
		char xc=xs[i];
		xs[i]=xs[j];
		xs[j]=xc;
	}
	for(int i=0,j=ys.size()-1;i<j;i++,j--){
		char xc=ys[i];
		ys[i]=ys[j];
		ys[j]=xc;
	}
	if(xssi>yssi){
		while(ys.size()<xssi) ys+='0';
		yssi=ys.size();
	}
	else if(xssi<yssi){
		while(xs.size()<yssi) xs+='0';
		xssi=xs.size();
	}
	for(int i=0;i<=xssi;i++){
		if(xs[i]==ys[i]){
			anss+='0';
		}
		else{
			anss+='1';
		}
	}
	for(int i=0,j=anss.size()-1;i<j;i++,j--){
		char xc=anss[i];
		anss[i]=anss[j];
		anss[j]=xc;
	}
	return two_ten(anss);
}
int yi_he(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		ans=yi(ans,a[i]);
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l+=0){
		bool h=0;
		for(int lo=1;lo<=n-l+1;lo++){
			int r=l+lo-1;
			if(yi_he(l,r)==k){
				ans++;
				l=r+1;
				h=1;
				break;
			}
		}
		if(h==0){
			l++;
		}
	}
	cout<<ans;
	return 0;
}
