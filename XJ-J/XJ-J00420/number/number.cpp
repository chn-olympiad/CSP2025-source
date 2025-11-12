#include <bits/stdc++.h>
using namespace std;
char s[1000001];
long long a[101];
int flag = 0;
stack <long long> p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s;
    long long num = 0;
    for(int i = 0; i < strlen(s); i++){
    	if(int(s[i]) >= 48 && int(s[i]) <= 57){
    		long long x = int(s[i]) - 48;
    		a[x]++;
    		num++;
    		if(x != 0){
    			flag = 1;
			}
		}
	}

	long long ans = 0;
	for(int i = 0; i <= 9; i++){
		if(a[i] != 0){
			long long l = a[i];
			for(int j = 1; j <= l; j++){
				p.push(i);
				a[i]--;
			}
		}
	}
	long long sum = 1;
	long long m = 0;
	int u = 0;
	while(!p.empty()){
		cout << p.top();
		p.pop();
	}
	/*while(!p.empty()){
		int tmp = 0;
		int qq;
		if(p.top() != 0){
			if(u == 3){
				ans *= p.top();
				//cout << ans;
				//break;

			}
			else{
				ans += p.top() * sum;

			}
			//tmp = p.top();
			p.pop();
			sum *= 10;
			m++;
			//qq = 1;
			u = 1;
		}
		else if(p.top() == 0 && flag != 0){
			if(ans == 0){
				ans = 10;
			}
			else{
				ans *= 10;

			}
			//tmp = p.top();
			p.pop();
			sum *= 10;
			m++;
			//qq = 2;
			if(u != 1){
				u = 3;

			}
			//cout << ans << " ";
		}
		else{
			break;
		}
		//cout << ans << " ";
		if(ans == 200){
			//cout << tmp << " " <<sum << " " << qq <<" ";
			break;
		}
		
	}
	cout << ans;*/
    return 0;
}
