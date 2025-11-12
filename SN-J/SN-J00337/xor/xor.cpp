//SN-J00337 张巍邺 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
int a[102];
bool st[102];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    memset(st,false,sizeof st);
	int n,k,ans=0;
	cin >> n >> k;
	for(int i =1; i<=n; i++) {
		cin >>a[i];
	}
	if(k==1) {
		for(int i =1; i<=n; i++) {
			if(a[i]==1) {
				ans++;
			}
		}
	}else if(k==0){
		for(int i =1; i<=n; i++) {
			if(a[i]==0) {
				ans++;
			}
		}
		for(int i =1; i<n; i++) {
			if(a[i]==a[i+1]&&st[i]==false&&a[i]!=0) {
				st[i] = true;
				st[i+1]=true;
				ans++;
			}
		}
	}
	cout <<ans;
	return 0;
}
