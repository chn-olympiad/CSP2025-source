#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int shuzu[maxn];
bool cmp(long long aa , long long bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,xiaor,hang=1,shangz;
	cin >> n >> m;
	long long shang = n*m;
	for(int i=1;i<=shang;i++){
		cin >> shuzu[i];
	}
	xiaor = shuzu[1];
	sort(shuzu+1,shuzu+1+shang,cmp);
	int i=0;
	shangz=shang;
	while(shang--){
		i++;
		if(shuzu[i] == xiaor){
			xiaor = i-1;
			break;
		}
	}
	for(int i=0;i<shangz;i++){
		if(xiaor+1 > n){
			hang++;
			xiaor = xiaor - n;
		}else{
			if(hang%2==0){
				cout <<hang <<" "<<  n-xiaor;
			}else{
				cout << hang << " "<<xiaor+1;
			}
			return 0;
		}
	}
	return 0;
} 
