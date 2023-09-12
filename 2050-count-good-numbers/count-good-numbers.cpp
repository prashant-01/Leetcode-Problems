class Solution {
public:
    int solve(long long x , long long n){
        long long nn = n;
        long long ans=1;
        while(nn > 0){
            if(nn & 1){
                ans = ((ans % 1000000007) * (x  % 1000000007 )) % 1000000007;
                nn -= 1;
            }
            else{
                x = ((x  % 1000000007 ) * (x  % 1000000007 )) % 1000000007;
                nn /= 2;
            }
        }
        return ans % 1000000007;
    }
    int countGoodNumbers(long long n) {
        long long n1 , n2;
        if(n & 1){
            n1 = n/2;
            n2 = n1 + 1;
        }
        else{
            n1 = n/2;
            n2 = n1;
        }
        long long ans1 = solve(5 , n2);
        long long ans2 = solve(4 , n1);
        return (ans1*ans2) % 1000000007;
    }
};