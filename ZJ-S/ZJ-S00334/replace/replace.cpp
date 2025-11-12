#include<bits/stdc++.h>
using namespace std;
long long d1[5000044],d2[5000044],d3[5000044],fac[5000044];
int len1[200044];
const int p=1e9+7,pp=131;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int z,x;
	cin>>z>>x;
	string a,s;
	int wz1=0,wz2=0;
	fac[0]=1;
	for(int i=1;i<=5000000;i++){
		fac[i]=(fac[i-1]*pp)%p;
	}
	for(int i=1;i<=z;i++){
		cin>>a>>s;
		len1[i]=a.size()+len1[i-1];
		int len=a.size();
		for(int j=0;j<len;j++){
			wz1++;wz2++;
			d1[wz1]=(d1[wz1-1]*pp+a[j]-'a')%p;
			d2[wz2]=(d2[wz2-1]*pp+s[j]-'a')%p;
		}
	}
	string d;
	for(int i=1;i<=x;i++){
		int ans=0;
		cin>>a>>s;
		d="";
		int lenn=a.size(),len11=0,len=0;
		if(lenn!=s.size()){
			cout<<"0\n";
			continue;
		}
		int q11=-1,q22=-1;
		long long ress=0,res=0;
		a="X"+a;s="X"+s;
		for(int j=1;j<=lenn;j++){
			d3[j]=(d3[j-1]*pp+a[j]-'a')%p;
			if(q11!=-1){
				len11++;
				ress=(ress*pp+s[j]-'a')%p;
			}
			if(a[j]!=s[j]){
				if(q11==-1){
					len11++;
					ress=(ress*pp+s[j]-'a')%p;
					q11=j;
				}
				q22=j;
				res=ress;
				len=len11;
			}
		}
		long long q1,q2;
		for(int j=1;j<=z;j++){
			for(int k=len1[j-1]+len;k<=len1[j];k++){
				q1=(d2[k]-d2[k-len]*fac[len]%p+p)%p;
				q2=res%p;
				if(q1==q2){
					q1=(d1[len1[j]]-d1[len1[j-1]]*fac[len1[j]-len1[j-1]]%p+p)%p;
					q2=(d3[q22+(len1[j]-k)]-d3[q22-(k-len1[j-1])]*fac[len1[j]-len1[j-1]]%p+p)%p;
					if(q1==q2)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
