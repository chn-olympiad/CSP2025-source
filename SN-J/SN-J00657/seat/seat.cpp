#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000],ar;
long double cnt,ansx,ansy,ttep;
bool cmp(long long aax,long long aay){
	return aax>aay;
}
int main(){
	//SN-J00657 Lianglinyi TYQJ	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ar=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++){
		cnt+=1.0;
		if(a[i]==ar){
			break;
		}
	}
	ansx=ceil(cnt/n*1.0);	
	ttep=(long long)(cnt)%n;
	if(ttep==0){
		ttep=n;
	}
	if((long long)(ansx)%2==0){
		ansy=n-ttep+1;
	}else{
		ansy=ttep;
	}
	cout<<ansx<<' '<<ansy;
	return 0;
}
