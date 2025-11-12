#include<bits/stdc++.h>
using namespace std;
long long n,m,s[1000],c[1000],way,ren[1000],ch;
string x;
int check(long long tian,long long yil,long long yimian){
	if(tian>n&&yimian<m){
		return 0;
	}
	if(yimian>=m){
		long long i=1;
		for(long long j=1;j+tian-1<=n;j++){
			i*=j;
			i%=998244353;
		}
		way+=i;
		way%=998244353;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		if(ren[i]==0){
			ren[i]=1;
			long long yimian2=yimian,yil2=yil;
			if(yil<c[i]&&s[tian]==1){
				yimian2++;
			}
			if(s[tian]==0||yil>=c[i]){
				yil2++;
			}
			check(tian+1,yil2,yimian2);
			ren[i]=0;
		}
	}
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getline(cin,x);
	getline(cin,x);
	for(long long i=1;i<=n;i++){
		s[i]=x[i-1]-48;
		if(s[i]==0){
			ch=1;
		}
	}
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	check(1,0,0);
	cout<<way;
	return 0;
}

