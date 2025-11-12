#include<bits/stdc++.h>
using namespace std;
int n,a[510000],s,k,b[2100000],r=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=(a[i]^a[i-1]);
	}
	for(int i=1;i<=2000000;i++)b[i]=-2;
	b[0]=0;
	for(int i=1;i<=n;i++){
		if(b[a[i]^k]>=r){
			s++,r=i;
			//cout<<b[a[i]^k]+1<<" "<<i<<endl;
		}
		b[a[i]]=i;
	}
	cout<<s;
	return 0;
}
//qwq
