#include<iostream> 
#include<cmath>
#include<string> 
int aaa[10000];
int bbb[10000];
using namespace std;
int main (){
	freopen("polygon2.in","r",stdin);
	freopen("polygon2.out","w",stdout);
	int a,b,c,d,e,f,g,n; 
	cin>>n;
	b = 0;
	c = 0;
	for (int i = 0;i<n;i++){
		cin>>a;
		aaa[i] = a;
		b = max(b,a);
	}
	for (int i = 0;i<n;i++){
		for (int j = i+1;j<n;j++){
			for (int k = j+1;k<n;k++){
				if (aaa[i]+aaa[j]+aaa[k] > 2*b){
					c+=1;
				}
			}
		}
	}
	for (int i = 0;i<n;i++){
		for (int j = i+1;j<n;j++){
			for (int k = j+1;k<n;k++){
				for (int l = k+1;l<n;l++){
					if (aaa[i]+aaa[j]+aaa[k]+aaa[l] > 2*b){
						c+=1;
					}
				}
			}
		}
	}
	for (int i = 0;i<n;i++){
		for (int j = i+1;j<n;j++){
			for (int k = j+1;k<n;k++){
				for (int l = k+1;l<n;l++){
					for (int m = l+1;m<n;m++){
						if (aaa[i]+aaa[j]+aaa[k]+aaa[l]+aaa[m] > 2*b){
							c+=1;
						}
					}
				}
			}
		}
	}

	cout<<c+2;
	
	
	
	return 0;
}
	 
