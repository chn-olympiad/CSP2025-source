#include<bits/stdc++.h>
using namespace std;
long long n,k,w,cnt,a[1000001],we=1;
long long yihuo(long long x,long long y){
	long long m=1024*1024*4,r=0;
	while(m>x&&m>y)m/=2;
	while(m>0){
		if(x>=m&&y<m){
			x-=m;
			r+=m;
		}
		else if(x<m&&y>=m){
			y-=m;
			r+=m;
		}
		else if(x>=m&&y>=m)x-=m,y-=m;
		m/=2;
	}
	return r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				for(int j=we+1;j<i;j++){
					w=yihuo(w,a[j]);
					if(w==k)cnt++;
					break;
				}
				we=i,cnt++,w=0;
			}
			else {
				w=yihuo(w,a[i]);
				if(w==k)w=0,cnt++;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
