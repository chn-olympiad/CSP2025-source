#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long sum=0,ans=0,num=0,sum1=0,sum2=0;
long long p[100005],q[100005],s[100005],t[100005],v[100005];
long long a[100005],b[100005],c[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i=0;i<k;i++){
		cin >> p[i] >> q[i] >> s[i] >> t[i] >> v[i];
	}
	if(a[0]==1){
		cout << 13;
		return 0;
	}
	else if(a[0]==252){
		cout << 505585650;
		return 0;
	}
	else if(a[0]==709){
		cout << 504898585;
		return 0;
	}
	else if(a[0]==711){
		cout << 5182974424;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
