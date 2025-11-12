#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n,q,t[maxn],l1,r1,ansr,ansl,ans;
string a2[maxn];
string q1,q2,q3,q4;
struct s{
	string x,y,x2,y2;
	int l,r;
}a[maxn];
bool cmp(s l,s r){
	return (l.x2 < r.x2 || (l.x2 == r.x2 && l.y2 < r.y2));
}
int finda(string x,int l,int r){
	if (l == r) return l;
	int mid = (l+r)/2;
	if (a2[mid] >= x) {
		//cout << l << " " << mid;
		//cout << a2[mid] << " " << x;
		return finda(x,l,mid);
	}
	else {
		//cout << l << " " << mid;
		//cout << a2[mid] << " " << x;
		return finda(x,mid+1,r);	
	}
}
int findb(string x,int l,int r){
	if (l == r) return l;
	int mid = (l+r)/2;
	if (a2[mid] > x) {
		//cout << l << " " << mid;
		//cout << a2[mid] << " " << x;
		return findb(x,l,mid);
	}
	else{
		//cout << mid+1 << " " << r;
		//cout << a2[mid] << " " << x;
		return findb(x,mid+1,r);
	} 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].y;
		int j = 0,r = a[i].x.length()-1;
		//string s1 = s2 = "";
		while(a[i].x[j] == a[i].y[j] && j < a[i].x.length()){
			j++;
		} 
		while(a[i].x[r] == a[i].y[r] && r >= j){
			r--;
		} 
		a[i].x2 = a[i].x.substr(j,r-j+1); 
		a[i].l = j;
		a[i].r = a[i].x.length()-r-1;
		a[i].y2 = a[i].y.substr(j,r-j+1);
		//cout << a[i].x2 << " " << a[i].y2 << "\n";
		//cout << j << " "<< r;
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n;i++) a2[i] = a[i].x2;
	//for (int i = 1;i <= n;i++) cout << a2[i] << " ";
	for (int i = 1;i <= q;i++){
		ans = 0;
		cin >> q1 >> q2;
		if (q1.length() != q2.length()){
			cout << "0\n";
			continue;
		}
		int j = 0,r = q1.length()-1;
		//string s1 = s2 = "";
		while(q1[j] == q2[j] && j < q1.length()){
			j++;
		} 
		while(q1[r] == q2[r] && r >= j){
			r--;
		} 
		q3 = q1.substr(j,r-j+1); 
		l1 = j;
		r1 = r;
		q4 = q2.substr(j,r-j+1);
		//cout << q3 << " " << q4 << "\n";
		ansl = finda(q3,1,n);
		ansr = findb(q3,1,n);
		if (ansr == n) ansr++;
		for (int i = ansl;i < ansr;i++){
			if (q3 != a[i].x2 || q4 != a[i].y2) continue;
			int u = l1-a[i].l,v = r1+a[i].r;;
			//cout << u << " " << v;
			if (u < 0 || v >= q1.length()) continue;
			if (q1.substr(u,v-u+1) == a[i].x && q2.substr(u,v-u+1) == a[i].y) ans++;
		}
		cout << ans << "\n";
		//cout << ansl << " " << ansr;
	}
	return 0;
}
