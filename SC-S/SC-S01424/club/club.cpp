#include<bits/stdc++.h>
using namespace std;
struct nn{
	int value;
	int p;
	int c;
};
struct child{
	nn n[4];
	int maxn;
};
child arr[111111];
bool cmp1(nn a , nn b){
	return a.value > b.value;
}
struct subject{
	int n;
	int i;
	int list[111111] = {};
};
bool cmp2(int a , int b){
	return arr[a].n[1].p > arr[b].n[1].p;
}
subject nu[4] = {};
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int T;
	cin >> T;
	while (T--){
		memset(arr , 0 , sizeof arr);
		memset(nu , 0 , sizeof nu);
		int n;
		cin >> n;
		int maxn = n / 2;
		for (int i = 1;i <= n;i ++){
			cin >> arr[i].n[1].value >> arr[i].n[2].value >> arr[i].n[3].value;
			arr[i].n[1].p = 1;
			arr[i].n[2].p = 2;
			arr[i].n[3].p = 3;
			sort(arr[i].n + 1 , arr[i].n + 4 , cmp1);
			arr[i].n[1].c = arr[i].n[1].value - arr[i].n[2].value;
			arr[i].n[2].c = arr[i].n[2].value - arr[i].n[3].value;
			nu[arr[i].n[1].p].n ++;
			nu[arr[i].n[1].p].list[nu[arr[i].n[1].p].i] = i;
			nu[arr[i].n[1].p].i ++;
		}
		int count = 0;
		for (int i = 1;i <= 3;i ++){
			if (nu[i].n != 0)sort(nu[i].list + 1 , nu[i].list + nu[i].i , cmp2);
			if (nu[i].n > maxn){
				for (int j = 0;j <= nu[i].n - maxn;j ++){
					swap(arr[nu[i].list[j]].n[1] , arr[nu[i].list[j]].n[3]);
					swap(arr[nu[i].list[j]].n[2] , arr[nu[i].list[j]].n[1]);
					nu[i].n --;
					nu[arr[nu[i].list[j]].n[1].p].n ++;
					nu[arr[nu[i].list[j]].n[1].p].list[nu[arr[nu[i].list[j]].n[1].p].i] = nu[i].list[j];
					nu[arr[nu[i].list[j]].n[1].p].i ++;
				}
			}
			for (int j = nu[i].i - nu[i].n;j <= nu[i].i;j ++){
				count += arr[nu[i].list[j]].n[1].value;
			}
		}
		cout << count << endl;
	}
	return 0;
}