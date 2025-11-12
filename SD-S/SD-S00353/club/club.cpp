#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,sum;
    cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
	    cin>>a>>b>>c;
		for(int j=1;j<=3;j++){
			if(a>=b){
			a=sum;
		}
		else{
			b=sum;
		}
		if(b>=c){
			b=sum;
		}
		else{
			c=sum;
		}
		}
	}
	cout<<sum<<endl;
	return 0;
}

