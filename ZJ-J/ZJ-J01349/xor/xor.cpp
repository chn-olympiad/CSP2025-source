#include<bits/stdc++.h>
using namespace std;
bool cnt[500010][21] = {0};
bool want[500010][21] = {0};
bool con[21] = {0};

bool tf(bool a,bool b){
	if(a == b)return 0;
	else{
		return 1;
	}
}

void change(long long num,int place){
	int w = 0;
	for(;num > 0;num /= 2){
		cnt[place][w] = num % 2;
		w++;
	}for(int i = 0;i<=20;i++){
		cnt[place][i] = tf(cnt[place][i],cnt[place-1][i]);
		want[place][i] = tf(cnt[place][i],con[i]);
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,ans = 0;
	long long k;
	scanf("%d",&n);
	cin >> k;
	int w = 0;
	for(;k > 0;k /= 2){
		con[w] = k % 2;
		w++;
	}
	int r = 1;
	for(int i=1;i<=n;i++){
		long long l;
		cin >> l;
		change(l,i);
		for(int j = i - 1;j >= r - 1;j--){
			bool is = 1;
			for(int y = 0;y <= 20;y++){
				if(want[i][y] != cnt[j][y]){
					is = 0;
					break;
				}
			}if(is == 1){
				ans++;
				r = i + 1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
