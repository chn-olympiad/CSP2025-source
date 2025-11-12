// I am a rubbish
// CCF我草泥马
// give me 1=
#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	int sum = 0;
	if(k == 0){
		a[n+1] = -1;
		for(int i = 1;i <= n;i++){
			if(a[i] == 0) sum++;
		}
		int cmax = 1;
		for(int i = 2;i <= n+1;i++){
			if(a[i] == a[i-1]) cmax++;
			else{
				for(int j = 1;j < cmax;j++){
					sum += j;
				}
				cmax = 1;
			}
		}
		cout << sum << endl;
		return 0;
	}
	else if(k == 1){
		int SUM = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				for(int l = i;l <= j;l++){
					if(b[l]){
						for(int ll = l;ll >= i;ll--) b[ll]--;
						SUM = 0;
						break;
					}
					if(a[l] == 1) SUM++;   
					b[l]++;  
				}
				if(SUM % 2 == 1) sum++;
				SUM = 0;
			}
		}
		cout << sum << endl;
		return 0;
	}
	else{
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				int x = 0;
				for(int l = i;l <= j;l++){
					if(b[l]){
						for(int ll = l;ll >= i;ll--) b[ll]--;
						break;
					}
					x ^= a[l];
					b[l]++;
				}
				if(x == k){
					sum++;
					//cout << i << " " << j << endl;
				}
			}
		}
		cout << sum << endl;
		return 0;
	}
	return 0;
}
//CCF我操你妈