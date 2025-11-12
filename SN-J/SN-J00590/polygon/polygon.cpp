//Àî¿¥Ãú Àî¿¥Ãú
 #include<bits/stdc++.h>
using namespace std;
int n;
int a[50005];
bool asd(int x,int y,int m=1){
	long long asdd=0;
	int sum[y-x+1];
	for (int i=x;i<=y;i++){
		sum[m]=a[i];
		asdd+=a[i];
		m++;
	}
	sort(sum+1,sum+m+1);
	if (asdd>2*sum[m]){
		return 1;
	}else{
		return 0;
	}
} 
long long sum;
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		
	}
	for (int i=1;i<=n-2;i++){
		for (int j=i+2;j<=n;j++){
			if (asd[i,j]){
				sum++;
				
			}
		}
	}
	cout << sum%998244353;
	return 0;
}
                                
