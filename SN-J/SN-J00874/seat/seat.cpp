// SN-J00874 管怡信 富阎高新初级中学
#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],Max,v;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
		v = a[1];
		if (a[i] > Max){
			Max=a[i];
		}
	}
	int i = Max-v+1;
	if (i%n==0){
		if ((i/n)%2==0){
		    cout << i/n<<" "<< 1;
		}else{
			cout << i/n<<" "<<n;
		}
	}else{
		if (i%n==1){
		    if ((i/n+1)%2==0){
			    cout << i/n+1<<" "<<n;
			}else{
	     		cout << i/n+1<<" "<<1;
			}
		}else{
			if ((i/n+1)%2==1){
				cout << i/n+1<<" "<<i%n;				     					
			}else{
				cout << i/n+1<<" "<<n*(i/n+1)-i+1;
				}
			}
	}
	return 0;
}
