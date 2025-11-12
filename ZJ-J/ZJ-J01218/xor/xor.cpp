#include<bits/stdc++.h>
using namespace std;
const long long N=500050;
int n;
long long k;
int a[N];
long long s[N];
int ret=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
//	cout<<((s[4]^s[2])^a[2])<<" "<<((a[2]^a[3])^a[4])<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(((abs(s[j]-s[i]))^a[i])==k){
//				cout<<i<<" "<<j<<" "<<((abs(s[j]-s[i]))^a[i])<<"\n";
				ret++;
				i=j;
				break;
			}
		}
	}
	printf("%d",ret);
	return 0;
}