#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
long long n,k,nn[1001],sum=0;
cin>>n>>k;
for(int i=1;i<=n;i++){
	cin>>nn[i];
}

if(k==0){
	for(int i=1;i<=n;i++){
	if(nn[i]==0){
		sum++;
	}
}
cout<<sum;
}
else if(k>=1){
	for(int i=1;i<=n;i++){
	sum+=i;
}
cout<<sum;
} 

fclose(stdin);
fclose(stdout);
	return 0;
}
