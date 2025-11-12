#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	long int n[t];
	long int a1[100001], a2[100001], a3[100001];
	long int sum = 0;
	int flag[3];
	memset(flag, 0, sizeof(flag));
	
	for(int i=0;i<t;i++){
		cin >> n[i];
		for(int j=0;j<n[i];j++){
			cin >> a1[j] >> a2[j] >> a3[j];
			sum += max(a1[j], max(a2[j], a3[j]));
			if(max(a1[j], max(a2[j], a3[j])) == a1[j]) flag[0] ++;
			if(max(a1[j], max(a2[j], a3[j])) == a2[j]) flag[1] ++;
			if(max(a1[j], max(a2[j], a3[j])) == a3[j]) flag[2] ++;
			
			int x = 0;
			if(flag[0] > n[i] / 2){
				flag[0] --;
				if(max(a1[j-1], max(a2[j-1], a3[j-1])) > max(a1[j], max(a2[j], a3[j])))
					sum -= max(max(a1[j-1], max(a2[j-1], a3[j-1])), max(a1[j], max(a2[j], a3[j])));
				else if(max(a1[j-1], max(a2[j-1], a3[j-1])) < max(a1[j], max(a2[j], a3[j])))
					sum -= min(max(a1[j-1], max(a2[j-1], a3[j-1])), max(a1[j], max(a2[j], a3[j])));
				else sum -= min(a1[j-1], a1[j-2]);
				for(int i=0;i<n[i];i++) x = max(max(a2[j], a3[j]), max(a2[j-1], a3[j-1]));
				sum += x;
			} 
			if(flag[1] > n[i] / 2){
				flag[1] --;
				if(max(a1[j-1], max(a2[j-1], a3[j-1])) > max(a1[j], max(a2[j], a3[j])))
					sum -= max(max(a1[j-1], max(a2[j-1], a3[j-1])), max(a1[j], max(a2[j], a3[j])));
				else if(max(a1[j-1], max(a2[j-1], a3[j-1])) < max(a1[j], max(a2[j], a3[j])))
					sum -= min(max(a1[j-1], max(a2[j-1], a3[j-1])), max(a1[j], max(a2[j], a3[j])));
				else sum -= min(a2[j-1], a2[j-2]);
				for(int i=0;i<n[i];i++) x = max(max(a1[j], a3[j]), max(a1[j-1], a3[j-1]));
				sum += x;
			} 
			if(flag[2] > n[i] / 2){
				flag[2] --;
				if(max(a1[j-1], max(a2[j-1], a3[j-1])) > max(a1[j], max(a2[j], a3[j])))
					sum -= max(max(a1[j-1], max(a2[j-1], a3[j-1])), max(a1[j], max(a2[j], a3[j])));
				else if(max(a1[j-1], max(a2[j-1], a3[j-1])) < max(a1[j], max(a2[j], a3[j])))
					sum -= min(max(a1[j-1], max(a2[j-1], a3[j-1])), max(a1[j], max(a2[j], a3[j])));
				else sum -= min(a3[j-1], a3[j-2]);
				sum += x;
			} 
		}
		
		cout << sum << endl;
		flag[0] = 0;
		flag[1] = 0;
		flag[2] = 0;
		sum = 0;
	}
	
	return 0;
}
