#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int k;
int a[100010];
struct node{
	int xb,s;
}zw[100010];
bool cmp(node s1,node s2){
	return s1.s>s2.s;
}
int b[100010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		zw[i].xb=i;
		zw[i].s=a[i];
	}
	sort(zw+1,zw+1+k,cmp);
	for(int i=1;i<=k;i++){
		b[zw[i].xb]=i;
	}
	int s2=b[1]/n;
//	cout<<b[1]<<endl;
	int s3=b[1]%n;
	if(s3==0){
		if(s2%2==1){
			cout<<s2<<" "<<n;
		}
		else cout<<s2<<" "<<1;
	}
	else{
		s2+=1;
//		cout<<s2<<endl;
		if(s2%2==1){
			cout<<s2<<" "<<s3;
		}
		else cout<<s2<<" "<<n-s3+1;
	}
	return 0;
}
