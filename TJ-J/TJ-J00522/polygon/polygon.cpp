#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e7+1314;
long long k,cnt,sum;
int a[N];
int amns(int l,int r){
	if(r>n) return 0;
	long long o;
	for(int i=l;i<=r;i++){
		o=(o+a[i])%998244353;
	}
	if(o>(a[r]*2)%998244353) cnt++;
	cnt=cnt%998244353;
	cout<<o<<endl;
	amns(l,r+1);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		amns(i,i+2);
	}
	cout<<cnt+2;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
