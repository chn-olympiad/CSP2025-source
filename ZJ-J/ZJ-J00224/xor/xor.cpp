//Let's make a force code!
//What amazing!This force slotion can run n=5e5 in 1s!(May this code won't TLE?)
//But I'm still worried about it.Because it O(nn).
//I tried much big data,but it never running expects 1s.That make me not very worry now.
//But maybe this computer's CPU is very strong?I dont't hope it.
//My English grammar is very bad.
#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int xorsum[500005];
int last_begin_id;
int ans;

int main(){
	ifstream cin("xor.in");
	ofstream cout("xor.out");
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		xorsum[i] = xorsum[i - 1] ^ a[i];
	}
	for(int i = 1;i <= n;i++){
//		cout<<"last_begin_id="<<last_begin_id<<"(Must delete it!)\n";
		for(int j = last_begin_id;j < i;j++){
			j = max(j,last_begin_id);
//			cout<<"i="<<i<<",j="<<j<<"(Must delete it!)\n";
			if((xorsum[j] ^ xorsum[i]) == k){
				last_begin_id = i;
//				cout<<"i="<<i<<"(Must delete it!)\n";
//				cout<<"last_begin_id="<<last_begin_id<<"(Must delete it!)\n";
				ans++;
//				cout<<"["<<j + 1<<","<<i<<"]="<<(xorsum[j] ^ xorsum[i])<<"(Must delete it!)\n";
			}
		}
	}
	cout<<ans;
	return 0;
}
