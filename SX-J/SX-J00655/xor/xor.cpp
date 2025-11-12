#include <iostream>
using namespace std;
    int a[1000],k,n,ans=0;
int main() {
	cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        if(a[i]=k){
            ans+=1;
		}
    }
    cout<<ans;
	return 0;
}
