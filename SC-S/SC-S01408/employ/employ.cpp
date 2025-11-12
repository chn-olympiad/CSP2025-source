#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} 
/*
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				long long l;
				cin>>l;
				if(l!=0){
					num++;
				}
			}
			long long ans=1;
			for(long long i=1;i<=num;i++){
				ans*=i;
			}
			cout<<ans;
		}
	}
	else if(s.find('0')!=string::npos){
		long long num=0;
		for(long long i=1;i<=n;i++){
			long long l;
			cin>>l;
			if(l==0){
				num++;
			}
		}
		if(n-num<m){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long ans=1;
		for(long long i=n-num;i>=m+1;i--){
			sum*=i;
			sum%=mod;
		}
		for(long long i=m;i>=1;i--){
			sum*=i;
			sum%=mod;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} #include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		if(s.find('0')!=string::npos){
			cout<<0;
		}
		else{
			long         long num=0;
			for(long long i=1;i                                        	long long l;
	=i;
 long ans=1;
		for(long long i=n-num;i>=m+1;i--){
\ */