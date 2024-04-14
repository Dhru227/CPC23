#include <iostream>
#include <vector>

class StockSpanner {
public:
    const int N = 1e5+5;
    std::vector<int> dp;
    std::vector<int> arr;
    StockSpanner() {
        dp.resize(N);
    }
    
    int next(int price) {
        if(!arr.empty()){
            int i = (int)arr.size()-1;
            while(i >= 0 && arr[i] <= price){
                i -= dp[arr[i]];
            }
            dp[price] = (int)arr.size()-i;
        }else dp[price] = 1;
        arr.push_back(price);
        return dp[price];
    }
};

int main() {
    StockSpanner stockSpanner;
    std::cout << stockSpanner.next(100) << std::endl; // return 1
    std::cout << stockSpanner.next(80) << std::endl;  // return 1
    std::cout << stockSpanner.next(60) << std::endl;  // return 1
    std::cout << stockSpanner.next(70) << std::endl;  // return 2
    std::cout << stockSpanner.next(60) << std::endl;  // return 1
    std::cout << stockSpanner.next(75) << std::endl;  // return 4
    std::cout << stockSpanner.next(85) << std::endl;  // return 6
    return 0;
}
