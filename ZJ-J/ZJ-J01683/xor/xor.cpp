#include<bits/stdc++.h>
using namespace std;
long long sr,i,j,c,x[500100],y[500100],ys,b[500100],n,m,k,a[500100],sum,s,maxn=INT_MIN,zzz,ans,l;
bool p1,p2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool p1=true,p2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)p1=false;
		if(a[i]>1) p2=false;
		b[i]=b[i-1]+a[i];
	} 
	if(p1){
		cout<<n/2;
		return 0;
	}//A
	if(p2){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					s++;
					if(sum%2==0&&sum>0) s++;
					sum=0;
				}
				if(a[i]==1){
					sum++;
				}
			}
			cout<<s;
		}
		if(k==1){
			cout<<b[n];
		}
		return 0;
	}//B
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j+=i){
//			for(int c=j;c<=j+i-1;c++){
//				if(c>n){
//					break;
//				}
//				l=l^a[c];
//				cout<<l<<' '<<i<<' '<<j<<' '<<c<<endl;
//			}
//			if(l==k){
//				ys++;
//				x[ys]=j;
//				y[ys]=j+i-1;
//			}
//		}
//	}
//	cout<<ys<<endl;
//	for(int i=1;i<=ys;i++){
//		cout<<x[i]<<' '<<y[i]<<endl;
//	}
	s=0;
	for(int i=1;i<=n;i++){
		l=0,s=0;
		for(int j=i;j<=n;j++){
			if(l==0)  ys=j; 
			l=(l^a[j]);
			s++;
			if(l>k){
				l=0;
				j=j-s+1;
				s=0;
				continue;
			}
 			if(l==k){
				ans++;
	//			cout<<i<<' '<<ys<<' '<<j<<endl;
			}
		}
		if(ans>maxn){
			maxn=ans;
			int zzz=i;
		}
		ans=0;
	}
	cout<<maxn;
	return 0;
}                          
