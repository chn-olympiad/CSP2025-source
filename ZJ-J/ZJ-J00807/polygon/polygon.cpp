#include<bits/stdc++.h>
using namespace std;
int n,ar[5010],sr[5010],s,c,m=998244353,cr[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> ar[i];
	}
	sort(ar+1,ar+n+1);
	for(int i=1;i<=n;i++){
		sr[i]=sr[i-1]+ar[i];
	}
	for(int i=3;i<=n;i++){
		if(sr[i-1]>ar[i]){
			c=0;
			for(int j=1;j<i;j++){
				if(ar[j]<sr[i-1]-ar[i]){
					c++;
				}
			}
			for(int j=1;j<i;j++){
				for(int z=j+1;z<i;z++){
					if(ar[j]+ar[z]<sr[i-1]-ar[i]){
						c++;
					}
				}
			} 
			s+=1+c;
		}
	}
	cout << s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
