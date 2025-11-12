#include<bits/stdc++.h>
using namespace std;
int n,ar[500010],sr[500010],k,vis[500010],re,c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	re=n;
	for(int i=1;i<=n;i++){
		cin >> ar[i];
		sr[i]=(sr[i-1] xor ar[i]);
		if(ar[i]==k){
			vis[i]++;
			re--;
			c++;
		}
	}
	for(int p=2;p<=re;p++){
		for(int i=1;i<=n;i++){
			if(re<p){
				break;
			}while(vis[i]){
				i++;
			}
			int j=i+1;
			while(vis[j]==0&&j<=n){
				j++;
			}
			while(i<=j-p){
				if((sr[i+p-1] xor sr[i-1])== k){
					for(int z=i;z<i+p;z++){
						vis[z]++;
					}
					re-=p;
					c++;
				}
				i++;
			}
		}
	}
	cout << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
