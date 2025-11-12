#include<bits/stdc++.h>
using namespace std;
long long n,m,h,l,cnt;
long long a[110];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)	cin>>a[i];
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==cnt){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0)	l=cnt/n;
	else	l=cnt/n+1;
	if(cnt%n==0){
		if(l%2==1)	h=n;
		else	h=1;
	}else{
		if(l%2==1)	h=cnt%n;
		else	h=n-cnt%n+1;
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

