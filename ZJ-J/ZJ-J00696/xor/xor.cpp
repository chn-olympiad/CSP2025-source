#include<bits/stdc++.h>
using namespace std;
int yh(long long int a,long long int b){
	if((a&b)==0) return (a|b);
	else if((a&b)==1){
		if((a|b)%2==1) return (a|b)-1;
		else return (a|b)+1;
	}
	return ( (!(a&b)) & (a|b) );
}
long long int num[1001][1001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	int ans=0;
	int p=0;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==k){
			ans++;
			p++;
		}
		else{
			for(int j=p;j<i;j++){
				num[j][i]=yh(a,num[j][i-1]);
				if(num[j][i]==k){
					ans++;
					p++;
					break;
				}
			}
			num[i][i]=a;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
