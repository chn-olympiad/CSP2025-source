#include<bits/stdc++.h>
using namespace std;
const int maxn = 555555;
int n,t;
struct stu{
	int m1,m2,m3,maxm;
}a[maxn];
bool cmp1(stu a,stu b){
	return (a.m1 >= a.m2 && a.m1 >= a.m3 && (b.m1 < b.m2 || b.m1 < b.m3))||(a.m1 >= a.m2 && a.m1 >= a.m3 && b.m1 >= b.m2 && b.m1 >= b.m3 && min(a.m1-a.m2,a.m1-a.m3) > min(b.m1-b.m2,b.m1-b.m3));
}
bool cmp2(stu a,stu b){
	return (a.m2 >= a.m1 && a.m2 >= a.m3 && (b.m2 < b.m1 || b.m2 < b.m3))||(a.m2 >= a.m1 && a.m2 >= a.m3 && b.m2 >= b.m1 && b.m2 >= b.m3 && min(a.m2-a.m1,a.m2-a.m3) > min(b.m2-b.m1,b.m2-b.m3));
}
bool cmp3(stu a,stu b){
	return (a.m3 >= a.m2 && a.m3 >= a.m1 && (b.m3 < b.m2 || b.m3 < b.m1))||(a.m3 >= a.m2 && a.m3 >= a.m1 && b.m3 >= b.m2 && b.m3 >= b.m1 && min(a.m3-a.m2,a.m3-a.m1) > min(b.m3-b.m2,b.m3-b.m1));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	long long sum1,sum2,sum3,ans;
	while(t--){
		cin >> n;
		int n2 = n/2;
		sum1 = 0,sum2 = 0,sum3 = 0,ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i].m1 >> a[i].m2 >> a[i].m3;
			a[i].maxm = max(a[i].m1,max(a[i].m2,a[i].m3));
			if(a[i].maxm == a[i].m1)sum1++;
			else if(a[i].maxm == a[i].m2)sum2++;
			else sum3++;
		}
		if(max(sum1,max(sum2,sum3)) <= n2){
			//cout << 1 << ' ';
			for(int i = 1;i <= n;i++){
				ans += a[i].maxm;
			}
			cout << ans << endl;
			continue;
		}
		if(max(sum1,max(sum2,sum3)) == sum1){
			sort(a+1,a+n+1,cmp1);
			//cout << "1| ";for(int i = 1;i <= n;i++)cout << a[i].m1 << ' ' << a[i].m2 << ' ' << a[i].m3 << "| " ;
			int i;
			for(i = 1;i <= n2;i++){
				if(a[i].maxm > a[i].m1)break;
				ans += a[i].m1;
			}
			for(;i <= n;i++){
				ans += max(a[i].m2,a[i].m3);
			}
		}
		else if(max(sum1,max(sum2,sum3)) == sum2){
			sort(a+1,a+n+1,cmp2);
			//cout << "2| ";for(int i = 1;i <= n;i++)cout << a[i].m1 << ' ' << a[i].m2 << ' ' << a[i].m3 << "| " ;
			int i;
			for(i = 1;i <= n2;i++){
				if(a[i].maxm > a[i].m2)break;
				ans += a[i].m2;
			}
			for(;i <= n;i++){
				ans += max(a[i].m1,a[i].m3);
			}
		}
		else {
			sort(a+1,a+n+1,cmp3);
			//cout << "3| ";for(int i = 1;i <= n;i++)cout << a[i].m1 << ' ' << a[i].m2 << ' ' << a[i].m3 << "| " ;
			int i;
			for(i = 1;i <= n2;i++){
				if(max(a[i].m1,max(a[i].m2,a[i].m3)) > a[i].m3)break;
				ans += a[i].m3;
			}
			for(;i <= n;i++){
				ans += max(a[i].m2,a[i].m1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}


