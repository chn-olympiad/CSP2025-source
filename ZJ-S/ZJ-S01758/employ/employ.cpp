#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m,a[100005];
    cin >> n >> m;
    char s[100005];
	bool t=1;
	int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
    	cin >> s[i];
		if(s[i]=='0') t=0;
		if(s[i]=='1') ans1++;
	}
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==0){
        	t=0;
        	ans2++;
		}
    }
    if(n==m){
        if(t==0){
        	cout << 0;
        	return 0;
		}
        else{
            int k=0;
            long long s=1;
            while(n-k!=0){
                s*=(n-k);
                k++;
            }
            cout << s%998244353;
            return 0;
        }
    }
    if(ans1<m||ans2>m){
    	cout << 0;
    	return 0;
	}
    return 0;
}
