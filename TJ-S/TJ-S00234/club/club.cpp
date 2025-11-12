#include <bits/stdc++.h>
using namespace std;
int t,n,a0[100],a1[100],a2[100];
int ans[100];
int cmp(int a,int b){
	return a > b;
}
void jjj(int coo){
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	int ma1[100] = { },ma2[100] = { },ma3[100] = { };
	for(int i = 1;i<=n;i++){
		if(a0[i] > a1[i] and a0[i] > a2[i]){
			ma1[i]=a0[i];cnt1++;
		}
		if(a1[i] > a0[i] and a1[i] > a2[i]){
			ma2[i]=a1[i];cnt2++;
		}
		if(a2[i] > a1[i] and a2[i] > a0[i]){
			ma3[i]=a2[i];cnt3++;
		}
	}
	sort(ma1+1,ma1+n+1,cmp);
	sort(ma2+1,ma2+n+1,cmp);
	sort(ma3+1,ma3+n+1,cmp);
	if(cnt1 > n / 2)cnt1 = n/2;
	if(cnt2 > n / 2)cnt2 = n/2;
	if(cnt3 > n / 2)cnt3 = n/2;
	for(int i = 1;i<=cnt1;i++)ans[coo]+=ma1[i];

	for(int i = 1;i<=cnt2;i++)ans[coo]+=ma2[i];

	for(int i = 1;i<=cnt3;i++)ans[coo]+=ma3[i];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i<=t;i++){
		cin >> n;
		for(int j = 1;j<=n;j++){
			cin >> a0[j] >> a1[j] >> a2[j];
		}
		jjj(i);
	}
	for(int i = 1;i<=t;i++)cout << ans[i] << endl;
	return 0;
} 

