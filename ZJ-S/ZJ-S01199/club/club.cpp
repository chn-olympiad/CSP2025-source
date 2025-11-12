#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,T,fa,fb,fc,k;
long long ans;
struct y{
	int a,b,c,d,o;
}t[maxn];
bool cmp(y l,y r){
	return l.d < r.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		k=ans=fa=fb=fc=0;
		cin >> n;
		for (int i = 1;i <= n;i++){
			cin >> t[i].a >> t[i].b >> t[i].c;
			k = max(t[i].a,max(t[i].b,t[i].c));
			ans+=k;
			if (k == t[i].a){
				t[i].o=1;
				fa++;
				t[i].d = k-max(t[i].b,t[i].c);
			}
			else if (k == t[i].b){
				t[i].o=2;
				fb++;
				t[i].d = k-max(t[i].a,t[i].c);				
			}
			else{
				t[i].o=3;
				fc++;
				t[i].d = k-max(t[i].b,t[i].a);
			}
		}	
		sort(t+1,t+n+1,cmp);
		if (fa > n/2){
			fa -= n/2;
			int i = 0,j=1;
			while(i < fa){
				if (t[j].o == 1){
					ans -= t[j].d;
					i++;
				}
				j++;
			} 
		}
		else if (fb > n/2){
			fb -= n/2;
			int i = 0,j=1;
			while(i < fb){
				if (t[j].o == 2){
					ans -= t[j].d;
					i++;
				}
				j++;
			} 
		}
		else if (fc > n/2){
			fc -= n/2;
			int i = 0,j=1;
			while(i < fc){
				if (t[j].o == 3){
					ans -= t[j].d;
					i++;
				}
				j++;
			} 
		}
		cout << ans << "\n";
	}

	return 0;
}
