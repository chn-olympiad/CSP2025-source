#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a,b,c,d,e,f,g,h,ans;
int aa[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>aa[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				sum=sum^aa[k];
			//	cout<<sum<<" ";
			}
			if(sum==b){
				//cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
