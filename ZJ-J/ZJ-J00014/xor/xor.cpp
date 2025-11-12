#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
int n,k,a[500005],now,x,sum[500005],ovo;
bool OUO;
int change(int xx,int yy){
	return (sum[xx]^sum[yy]);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sum[1]=a[1];
	x=1;
	for(int i=1;i<=n;i++){
		if(!OUO){
			sum[i]=(a[i]^sum[i-1]);
		}
		OUO=false;
		if(a[i]==k || sum[i]==k){
			x=i+1;
			ovo++;
			sum[i+1]=a[i+1];
			OUO=true;
//			cout<<i<<endl;
		}
		else{
			for(int j=x;j<=i-1;j++){
				if(change(j,i)==k){
					ovo++;
					x=i+1;
					sum[i+1]=a[i+1];
					OUO=true;
//					cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}
	}
//	cout<<endl<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
//	cout<<endl<<endl;
//	cout<<sum[982]<<" "<<sum[983]<<" "<<change(982,983)<<" ";
	cout<<ovo;
	return 0;
}
