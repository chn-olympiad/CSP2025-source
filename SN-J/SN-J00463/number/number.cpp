#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int ans;
int zm[1000010];
int zmgs=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int siz=s.size();
	for(int i=0;i<siz;i++){
		if(s[i]>='0'&&s[i]<='9'){
			zmgs++;
			zm[zmgs]=(s[i]-'0');
		}
	}
	sort(zm+1,zm+zmgs+1,cmp);
	for(int i=1;i<=zmgs;i++){
		cout<<zm[i];
	}
	return 0;
} 
