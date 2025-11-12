#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long n,k,a[N],c[N],num,ans; 
struct node{
	int u,v;
}e[N];
bool cmp(node x,node y){
	return x.v<y.v;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=2&&k==0){
		cout<<n/2;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]^a[i];
		}
	//	for(int i=1;i<=n;i++){
	//		cout<<c[i]<<" ";
	//	}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((c[j]^c[i-1])==k){
					num++;
					e[num].u=i,e[num].v=j;
				}
			}
		}
//		int i=1,j=1,p=1;
//		while(i<=j&&p<n){
//			if(c[p]^c[j-1]==k){
//				j=p;
//				num++;
//				e[num].u=j,e[num].v=p;
//			}
//			if(c[p]^c[i-1]==k){
//				i++;
//				num++;
//				e[num].u=i,e[num].v=p;
//			}
//			p++;
//		}
		sort(e+1,e+num+1,cmp);
//		for(int i=1;i<=num;i++){
//			cout<<e[i].u<<" "<<e[i].v<<endl;
//		}
		int la_v=0;
		for(int i=1;i<=num;i++){
			if(e[i].u>la_v){
				ans++;
				la_v=e[i].v;
			}
			else continue;
		}
		cout<<ans;
	}
	return 0;
}
