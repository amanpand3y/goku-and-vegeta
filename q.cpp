#include <bits/stdc++.h>
using namespace std;
void func2(long long n, unordered_map<long long,long long>& a) {
    if (n<=1) return;

    while(n%2==0) {
        a[2]++;
        n/= 2;
    }

    for(int i=3; i*i<=n; i+=2) {
        while(n%i==0) {
            a[i]++;
            n/= i;
        }
    }

    if(n>1) {
        a[n]++;
    }
}


void func(){
    long long a,b,k;
    cin>>a>>b>>k;

    unordered_map<long long,long long> x;
    unordered_map<long long,long long> y;
    unordered_map<long long,long long> diff;

    if(a==b){
        if(k==1){
            cout<<"NO"<<endl;
            return;
        }
    }

    func2(a,x);
    func2(b,y);

    for(auto it:x){
        if(x[it.first]!=y[it.first]){
            diff[it.first]=x[it.first]-y[it.first];
        }
    }
    for(auto it:y){
        if(x[it.first]!=y[it.first]){
            diff[it.first]=x[it.first]-y[it.first];
        }
    }

    long long cnt=k;

    if(k<diff.size()){
        cout<<"NO"<<endl;
        return;
    }
    long long diffsum=0;

    for(auto it:diff){
        diffsum+=abs(it.second);
    }
    
    if(diffsum>=k){
        cout<<"YES"<<endl;
        return;
    }
    cnt=cnt-diffsum;

    bool l=false;

    for(auto it:diff){
        if(it.second>0){
            x[it.first]=y[it.first];
            if(y[it.first]>0){
                l=true;
            }
        }
        else{
            y[it.first]=x[it.first];
            if(x[it.first]>0){
                l=true;
            }
        }
    }

    if(cnt==1){
        if(l){
            cout<<"YES"<<endl;
            return;
        }
        else{
            cnt=2;
        }
    }

    bool j=false;
    long long sum=0;

    for(auto it:x){
        sum+=it.second;
        if(it.second>=2){
            j=true;
        }
    }

    if(cnt>2*sum){
        cout<<"NO"<<endl;
        return;
    }

    if(cnt%2==1){
        if(j){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }

    if(cnt<=2*sum){
        cout<<"YES"<<endl;
    }
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        func();
    }
    
    
    return 0;
}
