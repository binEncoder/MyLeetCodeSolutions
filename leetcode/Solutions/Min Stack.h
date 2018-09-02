// 优雅，但是低效 17%
// pair的第二个元素就是当前情况下最小的元素值
class Solution_MinStack {
    stack<pair<int, int>> st;
public:
    void push(int x) {
        int min;
        if (st.empty()) {
            min = x;
        }
        else {
            min = std::min(st.top().second,x);
        }
        st.push({x, min});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};