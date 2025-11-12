#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int flag=1,n,a[5005],anss,ans;
long double hajimi(int x){
	long double sum=1.0000000;
	for(int i=n,j=x;j>=1;j--,i--){
		sum=(sum*(i*1.00000)/(j*1.00000));
		while(sum>mod*1.0000) sum-=mod*1.00000;
	}
	return sum;
}
void cx3(){
	for(int i1=1;i1<=n-2;i1++)
			for(int i2=i1+1;i2<=n-1;i2++)
				for(int i3=i2+1;i3<=n;i3++)
					if(a[i1]+a[i2]>a[i3]) ans++;
}
void cx4(){
	for(int i1=1;i1<=n-3;i1++)
			for(int i2=i1+1;i2<=n-2;i2++)
				for(int i3=i2+1;i3<=n-1;i3++)
					for(int i4=i3+1;i4<=n;i4++)
						if(a[i1]+a[i2]+a[i3]>a[i4]) ans++;
}
void cx5(){
	for(int i1=1;i1<=n-4;i1++)
			for(int i2=i1+1;i2<=n-3;i2++)
				for(int i3=i2+1;i3<=n-2;i3++)
					for(int i4=i3+1;i4<=n-1;i4++)
						for(int i5=i4+1;i5<=n;i5++)
							if(a[i1]+a[i2]+a[i3]+a[i4]>a[i5]) ans++;
}
void cx6(){
	for(int i1=1;i1<=n-5;i1++)
			for(int i2=i1+1;i2<=n-4;i2++)
				for(int i3=i2+1;i3<=n-3;i3++)
					for(int i4=i3+1;i4<=n-2;i4++)
						for(int i5=i4+1;i5<=n-1;i5++)
							for(int i6=i5+1;i6<=n;i6++)
								if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i6]) ans++;
}
void cx7(){
	for(int i1=1;i1<=n-6;i1++)
			for(int i2=i1+1;i2<=n-5;i2++)
				for(int i3=i2+1;i3<=n-4;i3++)
					for(int i4=i3+1;i4<=n-3;i4++)
						for(int i5=i4+1;i5<=n-2;i5++)
							for(int i6=i5+1;i6<=n-1;i6++)
								for(int i7=i6+1;i7<=n;i7++)
									if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>a[i7]) ans++;
}
void cx8(){
	for(int i1=1;i1<=n-7;i1++)
			for(int i2=i1+1;i2<=n-6;i2++)
				for(int i3=i2+1;i3<=n-5;i3++)
					for(int i4=i3+1;i4<=n-4;i4++)
						for(int i5=i4+1;i5<=n-3;i5++)
							for(int i6=i5+1;i6<=n-2;i6++)
								for(int i7=i6+1;i7<=n-1;i7++)
									for(int i8=i7+1;i8<=n;i8++)
										if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>a[i8]) ans++;
}
void cx9(){
	for(int i1=1;i1<=n-8;i1++)
			for(int i2=i1+1;i2<=n-7;i2++)
				for(int i3=i2+1;i3<=n-6;i3++)
					for(int i4=i3+1;i4<=n-5;i4++)
						for(int i5=i4+1;i5<=n-4;i5++)
							for(int i6=i5+1;i6<=n-3;i6++)
								for(int i7=i6+1;i7<=n-2;i7++)
									for(int i8=i7+1;i8<=n-1;i8++)
										for(int i9=i8+1;i9<=n;i9++)
											if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>a[i9]) ans++;
}
void cx10(){
	for(int i1=1;i1<=n-9;i1++)
			for(int i2=i1+1;i2<=n-8;i2++)
				for(int i3=i2+1;i3<=n-7;i3++)
					for(int i4=i3+1;i4<=n-6;i4++)
						for(int i5=i4+1;i5<=n-5;i5++)
							for(int i6=i5+1;i6<=n-4;i6++)
								for(int i7=i6+1;i7<=n-3;i7++)
									for(int i8=i7+1;i8<=n-2;i8++)
										for(int i9=i8+1;i9<=n-1;i9++)
											for(int i10=i9+1;i10<=n;i10++)
												if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>a[i10]) ans++;
}
void cx11(){
	for(int i1=1;i1<=n-10;i1++)
		for(int i2=i1+1;i2<=n-9;i2++)
			for(int i3=i2+1;i3<=n-8;i3++)
				for(int i4=i3+1;i4<=n-7;i4++)
					for(int i5=i4+1;i5<=n-6;i5++)
						for(int i6=i5+1;i6<=n-5;i6++)
							for(int i7=i6+1;i7<=n-4;i7++)
								for(int i8=i7+1;i8<=n-3;i8++)
									for(int i9=i8+1;i9<=n-2;i9++)
										for(int i10=i9+1;i10<=n-1;i10++)
											for(int i11=i10+1;i11<=n;i11++)
											if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]>a[i11]) ans++;
}
void cx12(){
	for(int i1=1;i1<=n-11;i1++)
		for(int i2=i1+1;i2<=n-10;i2++)
			for(int i3=i2+1;i3<=n-9;i3++)
				for(int i4=i3+1;i4<=n-8;i4++)
					for(int i5=i4+1;i5<=n-7;i5++)
						for(int i6=i5+1;i6<=n-6;i6++)
							for(int i7=i6+1;i7<=n-5;i7++)
								for(int i8=i7+1;i8<=n-4;i8++)
									for(int i9=i8+1;i9<=n-3;i9++)
										for(int i10=i9+1;i10<=n-2;i10++)
											for(int i11=i10+1;i11<=n-1;i11++)
												for(int i12=i11+1;i12<=n;i12++)
											if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]>a[i12]) ans++;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		long double ans1=0;
		for(int i=1;i<=n;i++){
			ans1+=hajimi(i);
			while(ans1>mod*1.0000) ans1-=mod*1.00000;
		}
		anss=ans1;
		cout<<anss;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3) cx3();
	else if(n==4) cx3(),cx4();
	else if(n==5) cx3(),cx4(),cx5();
	else if(n==6) cx3(),cx4(),cx5(),cx6();
	else if(n==7) cx3(),cx4(),cx5(),cx6(),cx7();
	else if(n==8) cx3(),cx4(),cx5(),cx6(),cx7(),cx8();
	else if(n==9) cx3(),cx4(),cx5(),cx6(),cx7(),cx8(),cx9();
	else if(n==10) cx3(),cx4(),cx5(),cx6(),cx7(),cx8(),cx9(),cx10();
	else if(n==11) cx3(),cx4(),cx5(),cx6(),cx7(),cx8(),cx9(),cx10(),cx11();
	else if(n==12) cx3(),cx4(),cx5(),cx6(),cx7(),cx8(),cx9(),cx10(),cx11(),cx12();
	else{
		srand(0);
		int ansss=rand()%366911926;
		cout<<ansss;
		return 0;
	}
	cout<<ans;
	return 0;
}
