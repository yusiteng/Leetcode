class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        std::vector<int> pointers(primes.size(),0);
        std::vector<int> temp(primes.size(),0);
        std::vector<int> ugly_nums(1,1);
        while (ugly_nums.size() < n){
            for (int i = 0; i < pointers.size(); ++i) {
                temp[i]= ugly_nums[pointers[i]]*primes[i];
            }

            auto myMin = min_element(temp.begin(), temp.end());
            for (int i = 0; i < pointers.size(); ++i) {
                if (*myMin == temp[i]){
                    pointers[i] += 1;
                }
            }
            ugly_nums.push_back(*myMin);
        }
        return ugly_nums.back();
    }
};