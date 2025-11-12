#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n, max=0, max1=0;
		int b[3]={0,0,0};
		cin >> n;
		for(int j=0;j<n;j++){
			int b[3];
			int a[3];
			int max=0;
			for(int l=0;l<3;l++){
				cin >> a[l];
				if(a[l]>max && b[l]<=n/2){
				    max=a[l];
				    b[l]++;
			    }
			}
			max1+=max;
		}
		cout << max1 << endl;
	}
	fclose(stdin);
    fclose(stdout); 
    return 0;
}
