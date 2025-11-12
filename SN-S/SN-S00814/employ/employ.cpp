#include <bits/stdc++.h>

int n,m,ans=0;
int h[500] = {0};
char str[500];

void dig(int i=0){
	int tmp;
	for (int x=0;x<n;x++){
		if(x==i){
			continue;
		}
		else{
			tmp=h[x];
			h[x]=h[i];
			h[i]=tmp;
			
			int faild=0,fogive=0,success=0;
			for (int t=0;t<n;t++){
				if (faild > h[t]){
					fogive++;
					continue;
				}
				if (fogive > h[t]){
					fogive++;
					continue;
				}
				if (str[t] == '0'){
					faild++;
				}
				else {
					success++;
				}
			}
			if (success>m){
				ans++;
			}
			
			tmp=h[x];
			h[x]=h[i];
			h[i]=tmp;
		}
	}
	
	if(i<(n-1)){
		dig(i++);
	}
}

int main(){
	freopen("employ2.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	std::cin >> n >> m;
	scanf("%s", str);
	for (int m=0;m<n;m++){
		std::cin >> h[m];
	}
	
	dig(0);
	
	std::cout << ans%998244353;
	
	return 0;
}
