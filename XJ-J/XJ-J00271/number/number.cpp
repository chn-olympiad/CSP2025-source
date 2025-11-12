#include<bits/stdc++.h>
using namespace std;
bool cmp(int aa,int bb){
	return aa>bb;
}
const int maxn = 1e5 + 10;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int h=0;
	cin >> s;
	int len = s.length();
	for(int i=0;i<=len;i++){
		if(s[i] >= '0' and s[i] <= '9'){
			h++;
			a[h] = s[i]-'0';
		}
	}
	sort(a+1,a+1+h,cmp);
	for(int i=1;i<=h;i++){
		cout << a[i];
	}
	return 0;
} 
