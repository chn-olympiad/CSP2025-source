#include<bits/stdc++.h>
using namespace std;
int a[500010],lst[500010],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int mx=0,i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>mx) mx=a[i];
	}
	if(mx==1){
		int cnt=0;
		for(i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		if(k==0) cout<<cnt/2;
		else if(k==1) cout<<cnt;
		else cout<<"???";
	}
	else{
		int x=0,y=1,xmi=0,cnt=0;
		while(1){
			if(y>=n) break;
			if(y<=x) {
				y++;
				x=xmi;
			}
			lst[x]=(lst[x] xor a[y]);
//			cerr<<"\n"<<x<<" "<<y<<"\n";
//			for(i=0;i<n;i++){
//				cerr<<lst[i]<<" ";
//			}
//			cerr<<"\n"<<lst[x]<<" "<<k<<"\n";
			if(lst[x]==k){
				y++;
				xmi=x+1;
				cnt++;
			}
			x++;
		}
		cout<<cnt;
	}
	return 0;
}

