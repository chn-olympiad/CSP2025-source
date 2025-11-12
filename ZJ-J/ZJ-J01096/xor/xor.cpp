#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;

struct node{
	int l,r;
}m[N];
int n,k,sum=1,num;
int a[N];
int b[N];
bool cmp(node x,node y){
//	return x.r-x.l<y.r-y.l;
	if(x.l==y.l)return x.r<y.r;
	return x.l<y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
//		cout<<b[i]<<" "<<(b[i]^b[i-1])<<endl;
	}
//	int i=0,j=1;
//	while(i<=n&&j<=n){
//		if(b[i]^b[j]==k){
//			i=j+1;
//			j=i+1;
//			sum++;
//		}else j++;
//	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((b[j]^b[i])==k){
				m[++num].l=i+1;
				m[num].r=j;
				break;
//				cout<<i+1<<" "<<j<<endl;
			}
		}
	}
//	cout<<num<<endl;
	if(num==0){
		cout<<0;
		return 0;
	}
	int tl=m[1].l,tr=m[1].r;
	for(int i=2;i<=num;i++){
		if(m[i].l>tr){
			sum++;
			tl=m[i].l,tr=m[i].r;
		}else if(m[i].l>tl&&m[i].r<=tr){
			tl=m[i].l,tr=m[i].r;
			
		}
	}
	cout<<sum;
	return 0;
}