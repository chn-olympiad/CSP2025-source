#include <bits/stdc++.h>
using namespace std;
long long t;
long long n,a1,a2,a3;
long long a11[500005],a22[500005],a33[500005];
long long v=-1;
long long csps=0;
long long yideng[500005],f=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			v=0;
			cin>>a1>>a2>>a3;
			a11[i]=a1;
			a22[i]=a2;
			a33[i]=a3;
			v=max(a11[i],a22[i]);
			v=max(v,a33[i]);
			csps+=v;
		}
		yideng[f]=csps;
		f++;
	}
	for(int i=1;i<=f;i++){
		cout<<yideng[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
long long t;
long long n,a1,a2,a3;
long long a11[500005],a22[500005],a33[500005];
long long v=0;
long long csps=0;
long long yideng[500005],f=1;
long long aa11=0,aa22=0,aa33=0;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	long long mn=t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			a11[i]=a1;
			a22[i]=a2;
			a33[i]=a3;
		}
		sort(a11+1,a11+1+n);
		sort(a22+1,a22+1+n);
		sort(a33+1,a33+1+n);
		for(int i=n;i>=1;i--){
			aa11=0;
			aa22=0;
			aa33=0;
			
			v=0;
			if(aa11<n/2 && aa22<n/2 && aa33<n/2){
				v=max(a11[i],a22[i]);
				v=max(v,a33[i]);
				csps+=v;
				if(v==a11[i]){
					aa11++;
				}else if(v==a22[i]){
					aa22++;
				}else{
					aa33++;
				}
				a11[i]=a22[i]=a33[i]=0;
			}else if(aa11==n/2 && aa22<n/2 && aa33<n/2){
				v=max(a22[i],a33[i]);
				csps+=v;
				if(v==a22[i]){
					aa22++;
				}else{
					aa33++;
				}
				a22[i]=a33[i]=0;
			}else if(aa11<n/2 && aa22==n/2 && aa33<n/2){
				v=max(a11[i],a33[i]);
				csps+=v;
				if(v==a11[i]){
					aa11++;
				}else{
					aa33++;
				}
				a11[i]=a33[i]=0;
			}else if(aa11<n/2 && aa22<n/2 && aa33==n/2){
				v=max(a22[i],a33[i]);
				csps+=v;
				if(v==a22[i]){
					aa22++;
				}else{
					aa33++;
				}
				a22[i]=a33[i]=0;
			}else if(aa11==n/2 && aa22==n/2 && aa33<n/2){
				v=a33[i];
				csps+=v;
				aa33++;
				a33[i]=0;
			}else if(aa11<n/2 && aa22==n/2 && aa33==n/2){
				v=a11[i];
				csps+=v;
				aa11++;
				a11[i]=0;
			}else if(aa11==n/2 && aa22<n/2 && aa33==n/2){
				v=a22[i];
				csps+=v;
				aa22++;
				a22[i]=0;
			}
		}
		yideng[f]=csps;
		f++;
		csps=0;
	}
	for(int i=1;i<=mn;i++){
		cout<<yideng[i]<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
*/
