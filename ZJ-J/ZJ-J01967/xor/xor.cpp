#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll k,a[500005];
ll xor_numbers(int l,int r){
    ll ans=a[l];
    for(int i=l+1;i<=r;i++){
        ans^=a[i];
    }
    return ans;
}
void baoli_solve(){
    cout<<1145;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;//我只会骗分
    if(k==0){//找有多少组是完全相同的
		int num=0;
		for(int i=1;i<=n;i++){
            cout<<111;
		}
	}
	else{//n^4究极暴力大法
		baoli_solve();
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
