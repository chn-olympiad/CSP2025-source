#include<bits/stdc++.h>
using namespace std;
short q[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int z,x,c=0,flag,ans;
	cin>>z>>x;
	for(int i=1;i<=z;i++){
		cin>>q[i];
		if(q[i]==1){
			c++;
			flag=i;
		}
	}ans=c/2;
	if((x==1 && c%2==0 && flag+1<=z)||(x==0 && c%2!=0 && flag+1<=z)){
		ans+=1;
	}cout<<ans;
	return 0;
}