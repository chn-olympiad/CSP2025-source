#include <bits/stdc++.h>
using namespace std;
int a[5010];
bool b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int cnt=0;
	if(n=3){
		for(int i=1;i<=n;i++){
			cin >> a[i];
	    }sort(a+1,a+1+n);
	    if(a[3]*2<a[1]+a[2]+a[3])cnt++;
	    cout << cnt;
	    return 0;
	}
	if(n=4){
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}sort(a+1,a+1+n);
		if(a[1]+a[2]+a[3]>a[3]*2)cnt++;
		if(a[1]+a[2]+a[4]>a[4]*2)cnt++;
		if(a[1]+a[3]+a[4]>a[4]*2)cnt++;
		if(a[2]+a[3]+a[4]>a[4]*2)cnt++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2)cnt++;
		cout << cnt;
		return 0;
	}
	return 0;
}

