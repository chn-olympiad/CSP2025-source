#include <bits/stdc++.h>
using namespace std;
int n,k,sum,p[500005];
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k) sum++,p[cnt++]=i;
	}
	int i=1,l=1,r=p[1]-1;
	while(i<cnt){
		if(l+1==r){
			l=p[i]+1;i++;r=p[i]-1;
			continue;
		}
		long long s=a[l];
		for(int j=l+1;j<=r;j++){
			s=s^a[j];
		}
		if(s==k) sum++;
		l=p[i]+1;
		i++;
		r=p[i]-1;
	}
	cout<<sum;
	return 0;
} 
