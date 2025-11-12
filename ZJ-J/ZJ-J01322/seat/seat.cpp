#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+n*m+1);
	int l = lower_bound(a+1,a+n*m+1,r)-a;
	//cout << a[l];
	int I_AK_IOI_is_sb = n*m-l+1;
	int sd = I_AK_IOI_is_sb/n;
	if(I_AK_IOI_is_sb%n==0){
		if(sd%2==0){
			cout << sd << " " << 1;
		}
		else{
			cout << sd << " " << n;
		}
	}
	else{
		int ds = I_AK_IOI_is_sb%n;
		if(sd%2==0){
			cout << sd+1 << " " << ds;
		}
		else{
			cout << sd+1 << " " << n-ds+1;
		}
	}
	return 0;
}
