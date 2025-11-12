#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,cnt=0;
int kkk(int m){
	int tmp=0;
	for(int i=m;i<=n;i++){
		tmp^=a[i];
		if(tmp==k) return i;
		int ss=tmp;
		for(int j=m;j<i;j++){
			ss^=a[j];
			if(ss==k) return i;
		}
	}
	return -1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int m=1,ans=kkk(m);
	while(ans!=-1){
		m=ans+1;
		cnt++;
		ans=kkk(m);
	}
	cout<<cnt;
	return 0;
}
