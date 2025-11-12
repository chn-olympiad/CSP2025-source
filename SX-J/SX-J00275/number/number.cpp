#include<bits/stdc++.h>
using namespace std;
int s[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;cin>>n;
    for(int i=0;i<=n;i++)
    {
    	cin>>s[i];
    	if(s[i]%1==0){
    		for(int j=1;j<=n;j++){
            int a=s[i]%10;
            s[i]=s[i]/10;
			cout<<a;
            }
		}
	}

	return 0;
}