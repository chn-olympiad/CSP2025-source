#include<bits/stdc++.h>
#include<stdio.h>
using namespace std; 
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin >> n >> k;
	if(k==0){
		for(int i=0;i<n;i++){
			cin >> a[i];
		} 
		int ans=0;
		int now=0;
		for(int i=0;i<n;i++){
			if(a[i]==k){
				ans++;
				now=i;
				continue;
			}
			int l=0;
			int sum=k^a[i]; 
			for(int j=i-1;j>now;j--){
				l^=a[j];
				if(l==sum){
					ans++;
					now=i;
					break;
				}
			}
		}
		cout << ans;
	}
	else if(k!=0){
		int len=0;
		int t=1;
		int cnt=0;
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			if(x!=0){
				a[len]=x;
				len++;
				if(len>=2&&a[len-1]!=a[len-2]){
					t=0;
				}
				else{
					cnt++;
				}
			} 
		}
		if(t==1){
			if(k==a[0]){
				cout << len;
			}
			else{
				cout << 0;
			}
		}
		else{
			int ans=0;
			int now=-1;
			for(int i=0;i<len;i++){
				if(a[i]==k){
					ans++;
					now=i;
					continue;
				}
				int l=0;
				int sum=k^a[i]; 
				for(int j=i-1;j>now;j--){
					l^=a[j];
					if(l==sum){
						ans++;
						now=i;
						break;
					}
				}
			}
			cout << ans;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
