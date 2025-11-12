#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
map<int,int> m;
int cnt=0;
int num[1000001];

int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); //yes
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++){
		int n=a[i]-'0';
		if(0<=n&&n<=9){
			if(m.count(n)==0){
				num[cnt]=n;
				cnt++;
			}
			m[n]++;
		}
	}
	sort(num,num+cnt);
//	for(int i=0;i<cnt;i++){
//		cout<<num[i];
//	}
	for(int i=cnt-1;i>=0;i--){
		for(int j=0;j<m[num[i]];j++){
			cout<<num[i];
		}
	}
}
