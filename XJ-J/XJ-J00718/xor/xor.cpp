#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxvv=5*1e5;
int n,k,a[maxvv];
string a_2[maxvv],xora[maxvv];
string TwoSystem(int x){
	string s,ans;
	while(x>0){
		if(x%2==1) s+="1";
		else s+="0"; 
		x/=2;
	}
	for(int i=s.length()-1;i>=0;i--)
		ans+=s[i];
	return ans;
}
string axor(string x,string y){
	string ans;
	int xlen=x.length();
	int ylen=y.length();
	string res,res1;
	if(xlen>ylen){
		for(int i=1;i<=xlen-ylen;i++)
			y+="0";
		for(int i=y.length()-1;i>=0;i--)
			res+=y[i];
		for(int i=ylen;i>=0;i--)
			res1+=y[i];
		for(int i=xlen-ylen;i>=0;i--)
			res[i]=res1[i];
		y=res;
	}
	else if(ylen>xlen){
		for(int i=1;i<=ylen-xlen;i++)
			y+="0";
		for(int i=x.length()-1;i>=0;i--)
			res+=x[i];
		for(int i=xlen;i>=0;i--)
			res1+=x[i];
		for(int i=ylen-xlen;i>=0;i--)
			res[i]=res1[i];
		x=res;
	}
	for(int i=0;i<max(xlen,ylen);i++){
		if(x[i]!=y[i])
			ans+="1";
		else
			ans+="0";
	}
	return ans;
}
int TenSystem(string x){
	int sum=0;
	for(int i=0;i<=x.length()-1;i++){
		if(x[i]=='1'){
			sum+=pow(2,i);
		}
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a_2[i]=TwoSystem(a[i]);
		if(i==1)
			xora[1]=a_2[1];
		if(i!=1)
			xora[i]=axor(xora[i-1],a_2[i]);
	}
	int cnt=0;
	for(int i=1;i<=n-k;i++){
		for(int j=1;j<=n-i;j++){
			if(TenSystem(axor(xora[i],xora[i+j]))==k){
				cnt++;
			}
		}
		
	}
	printf("%d",cnt);
	return 0;
}
