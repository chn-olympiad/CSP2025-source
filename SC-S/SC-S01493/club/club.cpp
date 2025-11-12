#include <bits/stdc++.h>
using namespace std;
int t,n,cnt=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	cin >> n;
	int a[n],b[n],c[n],l[t];
	for (int i=0;i<t;i++){
		int w = n/2;
		for (int j = 0;j<n;j++){
			cin >> a[j] >> b[j] >> c[j];
		}
		if (b[0] == 0 && c[0]==0){
			sort(a,a+n);
			
			for (int k = n-1;k>=n-w;k--){
				cnt+=a[k];
			}

		}
		l[i]=cnt;
		cnt = 0;
		if (i == t-1)
		break;
		cin >> n;
	}
	for (int i = 0;i<t;i++){
		cout << l[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}