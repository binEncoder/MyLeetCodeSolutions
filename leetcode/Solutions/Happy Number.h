#include "common.h"

class Solution_HappyNumber {
private:
	int digitNumSquareSum(int n){
		int sum = 0, tmp = 0;
		while(n){
			tmp = n%10;
			sum += tmp*tmp;
			n /= 10;
		}
		return sum;
	}
public:
	/* best beat 100%， fast数每个循环计算两次，slow数每个循环计算一次，
	 * 当fast与slow相等时，已经成环，不可能再发生别的变化组合，若此时slow不为1，则证明不是幸福数
	 */
    bool isHappy(int n) {
        int fast = n, slow = n;
		do{
			fast = digitNumSquareSum(fast);
			fast = digitNumSquareSum(fast);
			slow = digitNumSquareSum(slow);
		}while(fast != slow);
		return (slow == 1)?true:false;
    }
};

int main(int argc, char *argv[]){
	Solution_HappyNumber s;
	int input = 0;
	for(;;){
		cin>>input;
		string output = s.isHappy(input)?"true":"false";
		cout<<output<<endl;
	}
	return 0;
}
