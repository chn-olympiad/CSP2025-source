#include<bits/stdc++.h>
using namespace std;

#define int long long
int t;
struct stu{
	int a,b,c;
};
stu s[100005];
bool cmp1(stu a,stu b){
	return (a.a - max(a.b,a.c)) < (b.a - max(b.b,b.c));
}
bool cmp2(stu a,stu b){
	return (a.b - max(a.a,a.c)) < (b.b - max(b.a,b.c));
}
bool cmp3(stu a,stu b){
	return (a.c - max(a.b,a.a)) < (b.c - max(b.b,b.a));
}
vector<stu> a1,a2,a3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i =0;i<t;i++){
		a1.clear();
		a2.clear();
		a3.clear();
		int n;cin >> n;
		int SB = 1,SC = 0,summ = 0;
		for(int j =1;j<=n;j++){
			cin >> s[j].a >> s[j].b >>s[j].c;
		}
		for(int j =1;j<=n;j++){
			if(s[j].a > s[j].b and s[j].a > s[j].c){
				summ += s[j].a;
				a1.push_back(s[j]);
			}
			else if(s[j].b > s[j].a and s[j].b > s[j].c){
				summ += s[j].b;
				a2.push_back(s[j]);
			}
			else{
				summ += s[j].c;
				a3.push_back(s[j]);
			}
		}
//		cout << a1.size() << " " << a2.size() << " ";
		if(a1.size() > n/2){
			sort(a1.begin(),a1.end(),cmp1);
			for(int j =0;j + n/2 <a1.size();j++){
			//	cout << summ << " "<<(a1[j].a - max(a1[j].b,a1[j].c)) << endl;
				summ -= (a1[j].a - max(a1[j].b,a1[j].c));
			}
			cout << summ << endl;
		}
		else if(a2.size() > n/2){
			sort(a2.begin(),a2.end(),cmp2);
			for(int j =0;j + n/2 <a2.size();j++){
//				cout << summ << " "<< a2[j].b  << " " << max(a2[j].a,a2[j].c) << endl;
				summ -= (a2[j].b - max(a2[j].a,a2[j].c));
			}
			cout << summ << endl;
		}
		else if(a3.size() > n/2){
			sort(a3.begin(),a3.end(),cmp3);
			for(int j =0;j + n/2 <a3.size();j++){
				summ -= (a3[j].c - max(a3[j].b,a3[j].a));
			}
			cout << summ << endl;
		}
		else cout << summ << endl;
	}
	
	return 0;
}
