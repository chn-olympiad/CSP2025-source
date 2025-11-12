#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a[500007];
string s[500007];
int dp[500007][3];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int s1 = k;
	string s2;
	if(s1 == 0){
		s[0] = '0';
	}
	while(s1 != 0){
		char c = s1 % 2 + '0';
		s2 += c;
		s1 /= 2;
	}
	for(int j = s2.size() - 1; j >= 0; j--){
		s[0] += s2[j];
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		int s1 = a[i];
		s2 = '\0';
		if(a[i] == 0){
			s[i] = '0';
		}
		while(s1 != 0){
			char c = s1 % 2 + '0';
			s2 += c;
			s1 /= 2;
		}
		for(int j = s2.size() - 1; j >= 1; j--){
			s[i] += s2[j];
		}
	}
	int maxx = 0;
	for(int i = 1; i <= n; i++){
		if(dp[i][1] == 0){
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
		}
		else{
			dp[i][2] = dp[i - 1][2];
		}
		if(dp[i][1] == 0){
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
			if(s[i] == s[0]){
				dp[i][1]++;
			}
			else{
				int dou = 0;
				s2 = s[i];
				for(int j = i + 1; j <= n; j++){
					int minn = min(s2.size(), s[j].size());
					int big = max(s2.size(), s[j].size());
					string s3 = s[j];
					int yu1 = minn;
					for(; minn >= 0; minn--){
						if(s2[minn] != s3[minn]){
							s2[minn] = '1';
						}
						else{
							s2[minn] = '0';
						}
					}
					if(s3.size() > s2.size()){
						string yu;
						for(int k = 0; k < big - yu1; k++){
							yu += s3[k];
						}
						yu += s2;
						s2 = yu;
					}
					if(s2 == s[0]){
						dou = j;
						break;
					}
				}
				if(dou){
					dp[i][1]++;
					for(int j = i + 1; j <= dou; j++){
						dp[j][1] = dp[i][1]; 
					}
				}
			}
		}
		else{
			dp[i][1] = dp[i - 1][2];
			if(s[i] == s[0] && dp[i][1] + 1 > dp[i - 1][2]){
				dp[i][1]++;
			}
			else{
			int dou = 0;
			s2 = s[i];
			for(int j = i + 1; j <= n; j++){
				int minn = min(s2.size(), s[j].size());
				int big = max(s2.size(), s[j].size());
				string s3 = s[j];
				int yu1 = minn;
				for(; minn >= 0; minn--){
					if(s2[minn] != s3[minn]){
						s2[minn] = '1';
					}
					else{
						s2[minn] = '0';
					}
				}
				if(s3.size() > s2.size()){
					string yu;
					for(int k = 0; k < big - yu1; k++){
						yu += s3[k];
					}
					yu += s2;
					s2 = yu;
				}
				if(s2 == s[0]){
					dou = j;
					break;
				}
			}
			if(dou && dp[i][1] + 1 > dp[i - 1][2]){
				dp[i][1]++;
				for(int j = i + 1; j <= dou; j++){
					dp[j][1] = dp[i][1]; 
				}
			}else{
				dp[i][1] = dp[i - 1][1];
			}}
		}
		maxx = max(maxx, dp[i][1]);
		maxx = max(maxx, dp[i][2]);
	}
	cout << maxx;
	return 0;
}

