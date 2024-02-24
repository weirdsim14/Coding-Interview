#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // 로마 숫자와 그에 해당하는 정수 값을 매핑하는 map을 생성.
        map<char, int> romanValue = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int total = 0; // 총합을 저장할 변수를 0으로 초기화.
        // 문자열 s의 각 문자를 반복.
        for (int i = 0; i < s.length(); i++) {
            // 현재 문자가 다음 문자보다 작은 값을 나타내는 경우 (예: IV, IX),
            // 해당 값은 total에서 차감.
            if (i + 1 < s.length() && romanValue[s[i]] < romanValue[s[i + 1]]) {
                total -= romanValue[s[i]];
            } else {
                // 그 외의 경우에는 현재 문자에 해당하는 값을 total에 가산.
                total += romanValue[s[i]];
            }
        }
        return total; // 계산된 총합을 반환.
    }
};
