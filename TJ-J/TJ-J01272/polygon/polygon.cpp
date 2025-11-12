#include<bits/stdc++.h>
using namespace std;
int s[5010];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	sort(s,s+n);
	if(n<=10){
		for(int a=0;a<n;a++){
			for(int b=a+1;b<n;b++){
				for(int c=b+1;c<n;c++){
					if(s[a]+s[b]>s[c]){
						ans++;
					}
					for(int d=c+1;d<n;d++){
						if(s[a]+s[b]+s[c]>s[d]){
							ans++;
						}
						for(int e=d+1;e<n;e++){
							if(s[a]+s[b]+s[c]+s[d]>s[e]){
								ans++;
							}
							for(int f=e+1;f<n;f++){
								if(s[a]+s[b]+s[c]+s[d]+s[e]>s[f]){
									ans++;
								}
								for(int g=f+1;g<n;g++){
									if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]>s[g]){
										ans++;
									}
									for(int h=g+1;h<n;h++){
										if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]>s[h]){
											ans++;
										}
										for(int i=h+1;i<n;i++){
											if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]+s[h]>s[i]){
												ans++;
											}
											for(int j=i+1;j<n;j++){
												if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]+s[h]+s[i]>s[j]){
													ans++;
												}
											}
										}
									}
								}
								
							}
		
						}
					}
				}
			}
		}
	}
	cout<<ans; 
	return 0;
}
