#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin>>T;
	int a[100002];
	int b[100002];
	int c[100002];

	int dd[100002];
	int ee[100002];

	int p=0;
	int q=0;
	
	while (T--) {
		int n;
		cin>>n;
		int A=0;
		int B=0;
		
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			if(b[i] == 0 && c[i] == 0) {
				A=1;
			} else if(c[i] == 0) {
				B=1;
				if(b[i]>=a[i]) {
					dd[p+1]=b[i]-a[i];
					p++;//b大 
				} else if(a[i]>b[i]) {
					ee[q+1]=a[i]-b[i];
					q++;
				}               
			}
		}	
		
		if(A==1) {
			sort(a, a+n+1);
			int ans=0;
			for(int i=n; i>n/2; --i) ans+=a[i];
			cout<<ans<<endl;
		}
		
		if(B==1) {
			int ans = 0;
			for(int i=1; i<=n; i++) {
				ans+=a[i];
			}

			sort(dd,dd+p+1);
			sort(ee,ee+q+1);

			if(p >= n/2){
				int s=n/2;
				while(s--) {
					int i=p;
					ans+=dd[i];
					p--;
				}
			}else{
				while(p--) {
					int i=p;
					ans+=dd[i];
				}
				for(int i=1; i<=n/2-p; i++) ans-=ee[i];
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
} 