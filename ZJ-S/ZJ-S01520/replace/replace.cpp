#include<bits/stdc++.h>
#define int long long
using namespace std;
//map<string , string>mp;
const int N = 2e5 + 5;
struct node{
	string si , sj;
	int lens;
	int kais = -1 , mos;
};
node s[N];
signed main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n , q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
//		string si , sj;
//		cin >> si >> sj;
//		mp[si] = sj;
		cin >> s[i].si >> s[i].sj;
		s[i].lens = s[i].si.size() - 1;
		string zsi = s[i].si , zsj = s[i].sj;
		int lens = s[i].lens;
		for(int j=0;j<=lens;j++){
			if(zsi[j] != zsj[j]){
				if(s[i].kais == -1){
					s[i].kais = j;
				}
				s[i].mos = j;
			}
		}
	//	cout << s[i].kais << " " << s[i].mos << "sf" << endl;
	}
	while(q--){
		int ans = 0;
		string ti , tj;
		cin >> ti >> tj; 
		int len = ti.size() - 1;
		int kai = -1 , mo = -1;
		string kong = "" , dui = "";
		for(int i=0;i<=len;i++){
			if(ti[i] != tj[i]){
				if(kai == -1){
					kai = i;
				}
				mo = i;
				kong += ti[i];
				dui += tj[i];
			}
		}
//		cout << kai << " " << mo << "wssb" << endl;
//		cout << kong << " " << dui << "!!!" << endl; 
		for(int i=1;i<=n;i++){
			int ci = ti.find(s[i].si) , cj = tj.find(s[i].sj);
		//	cout << ci << " " << cj << "GG" << endl;
			if(ci == cj && cj != -1){
				int zi = s[i].si.find(kong) , zj = s[i].sj.find(dui);
			//	cout << zi << " " << zj << " " << s[i].kais << endl;
				if(zi == zj && zj == s[i].kais && s[i].kais != -1){
					ans++;
				}
			}
		} 
		cout << ans << endl;
	}
}
