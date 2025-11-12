#include<bits/stdc++.h>
using namespace std;
long long a[500010];
struct S{
	long long xi;
	long long ho;
}v[200010];
long long js[1010][1010];
bool cmp(S x,S y){
	if(x.ho==y.ho) return x.xi>y.xi;
	return x.ho<y.ho;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	bool f=1;
	long long p=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1 && a[i]!=0) f=0;
		if(a[i]==1) p++;
	}
	if(f && n>1001){
		if(k==1) cout << p;
		if(k==0){
			long long h=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) h++;
				if(i==n || a[i]==0) continue;
				int uf=0;
				while(a[i]==1 && i<=n){
					i++;
					uf++;
				}
				i--;
				h+=(uf/2);
			}
			cout << h;
		}
		return 0;
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j==i) js[i][j]=a[i];
			else js[i][j]=(long long)(js[i][j-1]^a[j]);
			if(js[i][j]==k){
				v[++cnt]={i,j};
			}
		}
	}
	sort(v+1,v+cnt+1,cmp);
	long long ans=0;
	long long r=1;
	long long zu=0;
	while(r<=cnt){
		ans++;
		zu=v[r].ho;
		r++;
		while(v[r].xi<=zu) r++;
	}
	cout << ans;
	return 0;
}
