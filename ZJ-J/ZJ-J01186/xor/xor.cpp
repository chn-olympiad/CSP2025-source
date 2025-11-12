#include<bits/stdc++.h>
using namespace std;
long long a[500005],f[2000005],n,k,cnt=0,p=0;
//map<int,int>f;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0]=0;
	f[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		if(f[a[i]^k]>=p&&((a[i]^k)==0||f[a[i]^k]!=0)){
			cnt++;
			p=i;
		}
		f[a[i]]=i;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

