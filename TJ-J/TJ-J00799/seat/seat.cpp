#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105],tmp;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    tmp=1;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
    	if(i!=1){
    		if(a[i]>a[1]){
    			tmp++;
			}
		}
	}
	int tmp2=tmp%n,tmp3=tmp/n;
	if(tmp2==0){
		tmp2=n;
	}
	if(tmp-n*tmp3!=0){
		tmp3++;
	}
	if(tmp3%2==0){
		cout<<tmp3<<' '<<n-tmp2+1;
	}
	else{
		cout<<tmp3<<' '<<tmp2;
	}
    return 0;
}
