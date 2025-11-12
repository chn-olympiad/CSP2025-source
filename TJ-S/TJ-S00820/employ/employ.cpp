#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	long long m,n,a[510];
	string s;

	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	sort(a,a+n);
	long long ans=1,bg=0;
    if(m==n){
        for(int i=2;i<=n;i++){
            ans*=i;
        }
    }else if(m==1){
        cout<<0;
        return 0;
    }else{
    	ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                bg++;
            }else{
                if(bg>=a[i]){
                    continue;
                }else{
                    ans++;
                }
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<ans;
	return 0;
}
