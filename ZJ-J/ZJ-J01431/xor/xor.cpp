#include<bits/stdc++.h>
using namespace std;
const int maxx = 5e5+5;
struct dxy{
	int x=0 , y=0;
};
bool cmp(dxy ll , dxy rr){
	if(ll.y != rr.y)return ll.y < rr.y;
	else return ll.x < rr.x;
}
int n , k;
int a[maxx];
dxy ans[maxx];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
	}
	int sum = 0;
	int l = 0;
	for(int i = 1 ; i <= n ; i++){
		sum = 0;
		for(int j = i ; j <= n ; j++){
			sum ^= a[j];
			if(sum == k){
				l++;
				ans[l].x = i;
				ans[l].y = j;
				break;
			}
		}
	}
	sort(ans+1,ans+l+1,cmp);
	int end = 0;
	int cnt = 0;
	for(int i = 1 ; i <= l ; i++){
		if(ans[i].x > end){
			cnt++;
			end = ans[i].y;
		}
	}
	cout << cnt;       
  fclose(stdin);fclose(stdout);
	return 0;
}
 
