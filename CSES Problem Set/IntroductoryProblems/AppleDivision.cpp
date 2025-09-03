#include <iostream> 

using namespace std;

long long helper(int idx, long long nums[], long long curr_sum, long long total_sum, int n) {
    if(idx == n) {
        return abs(total_sum - 2 * curr_sum);
    }

    long long pick = helper(idx + 1, nums, curr_sum + nums[idx], total_sum, n);

    long long skip = helper(idx + 1, nums, curr_sum, total_sum, n);

    return min(pick, skip);
}

int main() {
    int n; cin>>n;
    long long nums[n];
    long long total_sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
        total_sum += nums[i];
    }

    long long result = helper(0, nums, 0, total_sum, n);
    cout<<result;

    return 0;
}