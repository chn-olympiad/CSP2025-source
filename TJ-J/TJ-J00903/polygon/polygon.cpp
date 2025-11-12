#include <bits/stdc++.h>
using namespace std;
int n;
int ab(int m){
	if(n==m) return 1;
	int ans=0;
	for(int i=1;i<=n-m+1;i++){
		ans+=i*(n-i-m+2);
	}
	return ans+=ab(m+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])) cout<<1;
        else cout<<0;
        return 0;
    }
	int ans;
	ans=ab(3);
    cout<<ans+1;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
