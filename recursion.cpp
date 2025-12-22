#include <bits/stdc++.h>
#define nl '\n'
using namespace std;
using ll = long long;
using vin = vector<int>;
using vll = vector<ll>;
#define FastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool isprime(int x, int y) {
    if (y == 1) return true;
    else if (x % y == 0) return false;
    else return isprime(x,y-1);
}

// function for finding min element of an array 
int findMin(vector<int>& arr, int ind) {
    if (arr.size() - 1 == ind) {
        return arr[ind];
    }
    else return min(arr[ind], findMin(arr, ind + 1));
}

// print array in reverse order 
void printReverse(vin& arr, int n) {
    if (n == 0) return;
    cout << arr[n-1] << " ";
    printReverse(arr, n-1);
    
}

void printArray(vin& arr, int n) {
    if (n == 0) return;
    printArray(arr, n - 1);
    cout << arr[n-1] << " ";
}

// sum of first n elements : 
int arraySum(vin& arr, int n) {
    if (n == 0) return 0;
    else return arraySum(arr, n - 1) + arr[n-1];
}

// searching x in an array 
bool search(vin& arr, int n, int x) {
    if (n == 0) return false;

    if (arr[n-1] == x) return true;
    return search(arr,n-1,x);
}

bool isPalindrome(string s, int l, int r) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return isPalindrome(s, l+1,r-1);
}

// finding summation of first n natural numbers
int findsumofN(int n) {
    if (n == 0) return 0;
    else return n + findsumofN(n-1);
}

// sum of digits
int sumofdigits(int n) {
    if (n == 0) return 0;
    else return n%10 + sumofdigits(n/10);
}

void solve () {
    int n; cin >> n; 
    vin arr(n);
    for(auto& it : arr) {
        cin >> it;
    }    
    //printReverse(arr,n); cout << nl;
    //printArray(arr,n); cout << nl;
    //cout << arraySum(arr,n) << nl;
    //cout << search(arr,n, 5) << nl;
    // string s = "racecar";
    // cout << isPalindrome(s,0,s.size()-1) << nl;
    // cout << findsumofN(6) << nl;
    // cout << sumofdigits(3) << nl;
    

}

int main() {
    FastIO();
    int t = 1;
    //cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}