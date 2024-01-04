/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/binary-search/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <algorithm>
#include <cassert>
#include <chrono>
#include <doctest/doctest.h> //!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md
#include <iterator>
#include <queue>
#include <vector>
#include <set>
#include <span>

using namespace std;

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

class Solution {
public:
#if 0
    /*
        Based on indexing: [left, right]
    */
    int search(vector<int> const& nums, int const target) {
        ssize_t left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
               right = mid - 1;
            }
        }
        return -1;
    }
#else // #if 0
    /*
        Based on iterators: [left, right)
    */
    int search(vector<int>& nums, int target) {
        auto left = nums.begin();
        auto right = nums.end();
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (*mid < target) {
                left = mid + 1;
            } else if (*mid == target){
                return mid - nums.begin();
            } else {
                right = mid;
            }
        }
        return -1;
    }
#endif // #if 0
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

struct elapsed_time_t
{
    std::chrono::steady_clock::time_point start{};
    std::chrono::steady_clock::time_point end{};
    
    elapsed_time_t(
        std::chrono::steady_clock::time_point start
        , std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now()
    ) : start{std::move(start)}, end{std::move(end)} {}
};

std::ostream&
operator<<(std::ostream& os, elapsed_time_t const& et)
{
    auto const elapsed_time = et.end - et.start;
    os << std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count()
       << '.' << (std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time).count() % 1000)
       << " ms";
    return os;
}

TEST_CASE("Case 1")
{
    cerr << "Case 1" << '\n';
    vector<int> value{-1,0,3,5,9,12};
    auto const expected = 4;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        CHECK(expected == Solution{}.search(value, 9));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 10")
{
    cerr << "Case 10" << '\n';
    vector<int> value{};
    auto const expected = -1;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        CHECK(expected == Solution{}.search(value, 9));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 11")
{
    cerr << "Case 10" << '\n';
    vector<int> value{0};
    auto const expected = -1;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        CHECK(expected == Solution{}.search(value, 9));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 12")
{
    cerr << "Case 10" << '\n';
    vector<int> value{0};
    auto const expected = 0;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        CHECK(expected == Solution{}.search(value, 0));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 13")
{
    cerr << "Case 13" << '\n';
    vector<int> value{0, 1, 2};
    auto const expected = 1;
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        CHECK(expected == Solution{}.search(value, 1));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

/*
    End of "main.cpp"
*/
