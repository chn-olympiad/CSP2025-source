#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],bro,cnt,vis[500005];
struct node{
	long long l,r;
};
vector<node>v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] == 1){
			bro++;
		}
	}
	if(bro == n && k == 0){
		cout<<n/2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(k == 0){
		for(int i = 1;i <= n;i++){
			if(a[i] == 0){
				cnt++;
			}else if(a[i] == 1 && a[i-1] == 1 && vis[i-1] == 0 && vis[i] == 0){
				vis[i] = 1,vis[i-1] = 1;
				cnt++;
			}
		}
		cout<<cnt;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(k == 1){
		for(int i = 1;i <= n;i++){
			if(a[i] == 1){
				cnt++;
			}
		}
		cout<<cnt;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
