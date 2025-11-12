#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,a[N],b[N],ans;
void __scan(int l,int r,int c){
	for(int i=l;i<=r-c+1;i++){
		if((b[i-1]^b[i+c-1])==k){
			ans++;
			//cout<<i<<' '<<i+c-1<<endl;
			__scan(l,i-1,c+1);
			__scan(i+c,r,c);
			return;	
		}
	}
	if(r-l>=c)
		__scan(l,r,c+1);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	//	cout<<b[i]<<' ';
	}
//	cout<<endl;
	__scan(1,n,1);
	printf("%d",ans);
	return 0;
}
//J-00350