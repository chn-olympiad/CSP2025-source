#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n+2];
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	long long int ans = 0;
	if (k == 0){
		int f = false;
		for (int i=1;i<=n;i++){
			if (a[i] == 0)
				ans++;
			else{
				if (f == false)
					f = true;
				else{
					ans++;
					f = false;
				}
			}
		}
	}
	if (k == 1)
		for (int i=1;i<=n;i++)
			if (a[i] == 1)
				ans++;
	if (k != 1 && k != 0){
		for (int i=1;i<=n;i++){
			if (a[i] == k) {
				ans++;
				a[i] = -1;
				continue;
			}
			if (a[i] != -1){
				if (a[i-1] != -1){
					if (a[i]^a[i-1] == k) {
                    cout << a[i] << a[i-1];
					ans++;
					a[i] = -1;
					a[i-1] = -1;
					continue;
				}
				}
				else{
					int p = i-2;
					while (p > 1 && a[p] == -1) p--;
					if (a[p]^a[i] == k){
						ans++;
						a[p] = -1;
						a[i] = -1;
						continue;
					}
					else{
						a[i] = a[p]^a[i];
						a[p] = -1;
						continue;
					}
				}
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
