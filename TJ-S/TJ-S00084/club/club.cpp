#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100002],b[100002],c[100002],h[100002];
int sjle(){
	memset(a,0,100002);
	memset(b,0,100002);
	memset(c,0,100002);

	memset(h,0,100002);
	int sum=0; 
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> b[i] >> c[i];
		h[i-1]=min(a[i]-c[i],a[i]-b[i]);
		sum+=a[i];
		
	}
	
	sort(h,h+n);
	for(int i = 0;i<n/2;i++){
		sum-=h[i];
	
	}
	cout << sum << "\n";
	return 0;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> m;
	for(int i = 1;i<=m;i++){
		sjle();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
