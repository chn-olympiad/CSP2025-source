#include<bits/stdc++.h>
using namespace std;

int sum;
int n ,k;
int num [500005];
int fensum1,fensum2;
string strnum[500005];
int sum1[500005],sum2[500005];
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> num[i];
	}

	for(int k=0; k<n; k++) {
		for (int i=1; i<n; i++) {
			for (int j=0; j<i; j++) {
				if (fensum1%2==0&&num[i]%2==0) {
					fensum1+=num[i];
				} else if (fensum1%2==1&&num[i]%2==1) {
					fensum1-=1;
				} else if (fensum1%2==1&&num[i]%2==0&&fensum1>num[i]) {
					fensum1=1;
				} else if (fensum1%2==0&&num[i]%2==1&&fensum1>num[i]) {
					fensum1+=num[i];
				} else if (fensum1%2==1&&num[i]%2==0&&fensum1<num[i]) {
					fensum1=1;
				} else if (fensum1%2==0&&num[i]%2==1&&fensum1<num[i]) {
					fensum1+=num[i];
				}

				if (fensum2%2==0&&num[j]%2==0) {
					fensum2+=num[j];
				} else if (fensum2%2==1&&num[j]%2==1) {
					fensum2-=1;
				} else if (fensum2%2==1&&num[j]%2==0&&fensum2>num[j]) {
					fensum2=1;
				} else if (fensum2%2==0&&num[j]%2==1&&fensum2>num[j]) {
					fensum2+=num[j];
				} else if (fensum2%2==1&&num[j]%2==0&&fensum2<num[j]) {
					fensum2=1;
				} else if (fensum2%2==0&&num[j]%2==1&&fensum2<num[j]) {
					fensum2+=num[j];
				}
				
			}
			sum1[k]=fensum1;
			sum2[k]=fensum2;
			
		}

	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (sum1[i]==sum2[j]){
				sum++;
			}
		}
	}
	cout << sum+2;
	return 0;
}
