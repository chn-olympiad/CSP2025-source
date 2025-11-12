#include<bits/stdc++.h>
using namespace std;
int i;
int main()
{
    //freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int a[i];
	int n,j;
	cin>>n;
	cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>=0) continue;
		else{
			for(int j=1;j<=n;j++){
				a[j]=a[j+i];
			}
		}
	}
	cout<<a[j]<<endl;
	return 0;
}

