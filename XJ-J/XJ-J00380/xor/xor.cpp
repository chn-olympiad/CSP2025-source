#include <bits/stdc++.h>

using namespace std;

int n,temp,cnt,fez,s,e,ss,ee,nf;
long long k;
long long xl[500050];


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> xl[i];
		if (xl[i]==0) temp = 1;
	}
	if (k==0){
		s = 1;
		e = n;
		if (temp == 1){ 
			if (xl[1]==0){
				for (int i=1;i<=n;i++){
					if (xl[i]==1) fez += i;
					s = i;
				}
			}
			if (xl[n]==0){
				for (int i=n-1;i>=1;i--){
					if (xl[i]==1) fez += i;
					e = i;
				}				
			}
			for (int i=s;i<=e;i++){
				if (xl[i]==0){
					fez++;
				}
			}
			for (int i=s;i<=e;i++){
				if (xl[i] == 1){
					ss = i;
					for (int j = i;j<=e;j++){
						if (xl[j] == 1){
							nf = 1;
							ee = j;
							break;
						}
					}
					if (nf==1){
						fez -= ee-ss-2;
						nf = 0;
					}else{
						cnt = fez;
						break;
					}
				}
			}
		}else{
			cnt = n/2;
		}
	}else if (k==1){
		for (int i=1;i<=n;i++){
			if (xl[i]==1) cnt++;
		}
	} 
	cout << cnt;
	return 0;
}
