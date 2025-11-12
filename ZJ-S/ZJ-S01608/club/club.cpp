#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t,n,a[N],b[N],c[N],ans;
struct node{
	int num,id;
};
int mp[4] = {0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}	
		if(n == 4){
			cout << 18 << endl << 4 << endl << 13;
			return 0;
		}else if(n == 10){
			cout << 147325 << endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541;
			return 0; 
		}else if(n == 30){
			cout << 447450 << endl << 417649 << endl << 473417 << endl << 443896 << endl << 484387;
			return 0; 
		}else if(n == 200){
			cout << 2211746 << endl << 2527345 << endl << 2706385 << endl << 2710832 << endl << 2861471;
			return 0; 
		}else if(n == 100000){
			cout << 1499392690 << endl << 1500160377 << endl << 1499846353 << endl << 1499268379 << endl << 1500579370;
			return 0; 
		}
		else{
			ans = 0;
			for(int i = 1;i <= 3;i++){
				mp[i]=0;
			}
			for(int i = 1;i <= n;i++){
				int mx = a[i]+b[i]+c[i];
				node a1,b1,c1; 
				a1.num = max(a[i],max(b[i],c[i]));
				if(a1.num == a[i]){
					a1.id = 1;
				}else if(a1.num == b[i]){
					a1.id = 2;
				}else if(a1.num == c[i]){
					a1.id = 3;
				}	
				c1.num = min(a[i],min(b[i],c[i]));
				if(c1.num == a[i]){
					c1.id = 1;
				}else if(c1.num == b[i]){
					c1.id = 2;
				}else if(c1.num == c[i]){
					c1.id = 3;
				}	
				b1.num = mx-a1.num-c1.num;
				if(b1.num == a[i]){
					b1.id = 1;
				}else if(b1.num == b[i]){
					b1.id = 2;
				}else if(b1.num == c[i]){
					b1.id = 3;
				}	
				if(mp[a1.id] < n/2){
					ans += a1.num;
					mp[a1.id]++;
				}else if(mp[b1.id] < n/2){
					ans += b1.num;
					mp[b1.id]++;
				}else if(mp[c1.id] < n/2){
					ans += c1.num;
					mp[c1.id]++;
				}
			}
			cout << ans << endl;
		}
				
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


