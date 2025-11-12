#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p=0,num=0;
    cin >> n;
    int a[1000];
    for(int i=1;i<=n;i++){
    	cin >> a[i];
    	
	}
    for(int i=1;i<=n;i++){
    	for(int j=3;j<=n;j++){
    		for(int m=i;m<=i+j;m++){
    			p=p+a[m];
			}
			if(p>2*a[n]){
				num++;
			}
			p=0;
		}
	}
	cout << num;
	return 0;
}
