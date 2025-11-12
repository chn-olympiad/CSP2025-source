#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	int z=0;
		for(int j=0;j<n;j++){
			z=z+a[j];
				
		}
	cout<<z%15;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
